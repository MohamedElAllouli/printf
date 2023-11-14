#include "main.h"

/************************* UNSIGNED NUMBER *************************/
/**
 * p_unsigned - Prints unsigned number
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: specification
 * @size: specifier size
 * Return: number of chars printed.
 */
int p_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * p_octal - Prints an unsigned number in octal notation
 * @types: arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: specifier size
 * Return: number of chars printed
 */
int p_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * p_hexadecimal - Print an unsigned number in hexadecimal notation
 * @types:  arguments
 * @buffer: Buffer a
 * @flags:  active flags
 * @width: width
 * @precision: Precision of  specification
 * @size: Size
 * Return: Number of chars
 */
int p_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * p_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: number of chars printed
 */
int p_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** HEXX NUMBER IN LOWER CASE OR UPPER CASE **************/
/**
 * p_hexa - Prints a hexadecimal number in lower case  or upper case
 * @types: arguments
 * @map_to: values to map the number to
 * @buffer: Buffer array
 * @flags:  Calculates
 * @flag_ch: active flags
 * @width: width
 * @precision: specification
 * @size: specifier size
 * @size: specification size
 * Return: number of chars printed
 */
int p_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
