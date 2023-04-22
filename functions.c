#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * get_function - look for the function
 * @x: variable to the function
 * Return: function
 */

int (*get_function(char x))(va_list)
{
	int i = 0;
	spc arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};
	while (arr[i].valid)
	{
		if (x == arr[i].valid[0])
			return (arr[i].f);
		i++;
	}
	return (NULL);
}

/**
 * print_c - prints character
 * @args: character argument
 * Return: number of characters
 */

int print_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_s - prints a string
 * @args: string  argument
 * Return: number of characters
 */

int print_s(va_list args)
{
	int i, count = 0;
	char *str;

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

/**
 * print_percent - pass the percent sing
 * @args: string  argument
 * Return: return the percent sing
 *
 */

int print_percent(va_list args)
{
	char *str;

	str = "%";
	if (va_arg(args, int) == *str)
	{
		return (*str);
	}
	return (*str);
}

/**
 * print_d - prints decimal (base 10) number
 * @args: argument containing the integer to print
 * Return: number of characters number of characters printed
 */

int print_d(va_list args)
{
	int d;

	d = va_arg(args, int);
	return (printf("%d", d));
}

/**
 * print_i - prints an integer
 * @args: integer  argument
 * Return: number of characters the number of characters printed
 */

int print_i(va_list args)
{
	int i;

	i = va_arg(args, int);
	return (printf("%i", i));
}
