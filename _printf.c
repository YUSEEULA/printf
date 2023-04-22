#include "main.h"
#include <unistd.h>

/**
 * _printf - function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;

	int index = 0, counter = 0;
	char c, *string;

	va_start(args, format);

	while (format != NULL && format[index] != '\0')
	{
		if (format[index] == '%')
		{
			switch (format[index + 1])
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					counter++;
					index++;
					break;
				case 's':
					string = va_arg(args, char *);
					if (string != NULL)
					{
						write(1, string, 1);
						string++;
						counter++;
					}
					index++;
					break;
				default:
					write(1, &format[index], 1);
					counter++;
					break;
			}
		}
	}
	va_end(args);
	return (counter);
}
