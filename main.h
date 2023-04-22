#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);

/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */

typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
}

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);
int (*get_function(char x))(va_list args);
#endif
