#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*flag */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*size*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct
 * * @fmt: format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct
 * * @fmt: format.
 * @fm_t: function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_p(const char *fmt, int *i, va_list list, char buffer[], int flags,
		int width, int precision, int size);

/****************** All Functions ******************/

/* Print chars and strings */
int p_char(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_string(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Print numbers */
int p_int(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int p_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int p_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

/* Print non printable characters */
int p_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Funcion to print memory address */
int p_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* get - handle other specifiers */
int g_flags(const char *format, int *i);
int g_width(const char *format, int *i, va_list list);
int g_precision(const char *format, int *i, va_list list);
int g_size(const char *format, int *i);

/* Print string in reverse*/
int p_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size);

/* Print a string in rot 13*/
int p_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* width of  handler */
int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags,
		int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags,
		char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size);

/****************** FUNCTIONS UTILS ******************/
int isprintable(char);
int append_hexa_code(char, char[], int);
int digit_is(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
