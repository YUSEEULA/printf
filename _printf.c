#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	int (*m)(va_list);
	va_list args;

	if (format != NULL)
	{
		va_start(args, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != NULL && format[i] != '\0')
		{
			if (format[i] == '%')
			{
				m = get_func(format[i + 1]);
				if (m)
					count += m(args);
				else
					count = _putchar(format[i]) + _putchar(format[i + 1]);
				i += 2;
			}
			else
			{
				count += _putchar(format[i]);
				i++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}
