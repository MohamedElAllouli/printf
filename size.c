#include "main.h"

/**
 * g_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * * Return: Precision.
 */
int g_size(const char *format, int *i)
{
	int c_i = *i + 1;
	int s = 0;

	if (format[c_i] == 'l')
		s = S_LONG;
	else if (format[c_i] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = c_i - 1;
	else
		*i = c_i;

	return (s);
}
