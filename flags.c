#include "main.h"

/**
 * g_flags - Calculate active flags
 * @format: string in which to print the arguments
 * @i: parameter.
 * Return: Flags:
 */
int g_flags(const char *format, int *i)
{
	int j, c_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[c_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = c_i - 1;

	return (flags);
}
