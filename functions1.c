#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_u - Function that prints an unsigned number
 * @num: Number to be printed
 * Return: Number of digits printed
 */

int print_u(unsigned int num)
{
	int digits = 0;
	char buffer[20];

	do {
		buffer[digits++] = (num % 10) + '0';
		num = num / 10;
	} while (num != 0);

	while (digits > 0)
	{
		digits--;
		if (write(1, &buffer[digits], 1))
			return (-1);
	}

	return (digits);
}

/**
 * print_o - Function that prints a number in octal
 * @num: Number to be printed
 * Return: Number of digits printed
 */

int print_o(unsigned int num)
{
	int digits = 0;
	char buffer[22];

	do {
		buffer[digits++] = (num % 8) + '0';
		num = num / 8;
	} while (num != 0);

	while (digits > 0)
	{
		digits--;
		if (write(1, &buffer[digits], 1) == -1)
			return (-1);
	}

	return (digits);
}

/**
 * print_x - Function that prints number in hexadecimal
 * @num: Number to be printed
 * Return: Number of digits printed
 */

int print_x(unsigned int num)
{
	int digits = 0;
	char buffer[10];

	do {
		buffer[digits++] = "0123456789abcdef"[num % 16];
		num = num / 16;
	} while (num != 0);

	while (digits > 0)
	{
		digits--;
		if (write(1, &buffer[digits], 1) == -1)
			return (-1);
	}

	return (digits);
}

/**
 * print_X - Function that prints number in hexadecimal in uppercase
 * @num: Number to be printed
 * Return: Number of digits printed
 */

int print_X(unsigned int num)
{
	int digits = 0;
	char buffer[10];

	do {
		buffer[digits++] = "0123456789ABCDEF"[num % 16];
		num = num / 16;
	} while (num != 0);

	while (digits > 0)
	{
		digits--;
		if (write(1, &buffer[digits], 1) == -1)
			return (-1);
	}

	return (digits);
}
