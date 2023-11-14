#include "main.h"

/**
 * p_buffer - Prints buffer
 * @buf: array
 * @ind_buf: Index.
 */
void p_buffer(char buf[], int *ind_buf)
{
	if (*ind_buf > 0)
		write(1, &buf[0], *ind_buf);

	*ind_buf = 0;
}

/**
 * _printf - Printf function
 * @format: format to print.
 * Return: char printed
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p_chars = 0;
	int f, w, pr, s, ind_buf = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[ind_buf++] = format[i];
			if (ind_buf == BUFF_SIZE)
				p_buffer(buffer, &ind_buf);
			p_chars++;
		}
		else
		{
			p_buffer(buffer, &ind_buf);
			f = get_flags(format, &i);
			w = get_width(format, &i, list);
			pr = get_precision(format, &i, list);
			s = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
				f, w, pr, s);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}

	p_buffer(buffer, &ind_buf);

	va_end(list);

	return (p_chars);
}
