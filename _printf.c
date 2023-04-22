#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>

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
				if (format[i + 1] == '%')
					count += write(1, &format[i + 1], 1);
				else
				{
					m = get_function(format[i + 1]);
					if (m)
						count += m(args);
					else
						count += write(1, &format[i], 1) + write(1, &format[i + 1], 1);
				}
				i += 2;
			}
			else
			{
				count += write(1, &format[i], 1);
				i++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}
