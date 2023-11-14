#include "main.h"

/**
 * g_width - Calculates the width for printing
 * @format: string in which to print the arguments.
 * @i: arguments to be printed.
 * @list: arguments.
 *
 * Return: width.
 */
int g_width(const char *format, int *i, va_list list)
{
	int c_i;
	int w = 0;

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		if (digit_is(format[c_i]))
		{
			w *= 10;
			w += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (w);
}
