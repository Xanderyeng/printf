#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_unsigned - prints an unsigned integer
 * @args: argument list containing the unsigned integer
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, j;

	if (num == 0)
		return (_putchar('0'));
	while (num != 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(buffer[j]);
	return (i);
}

/**
 * print_octal - prints an octal number
 * @args: argument list containing the octal number
 *
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, j;

	if (num == 0)
		return (_putchar('0'));
	while (num != 0)
	{
		buffer[i] = (num % 8) + '0';
		num /= 8;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(buffer[j]);
	return (i);
}

/**
 * print_hex - prints a hexadecimal number
 * @args: argument list containing the hexadecimal number
 *
 * Return: number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, j;

	if (num == 0)
		return (_putchar('0'));
	while (num != 0)
	{
		int remainder = num % 16;
		if (remainder < 10)
			buffer[i] = remainder + '0';
		else
			buffer[i] = remainder + 'a' - 10;
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(buffer[j]);
	return (i);
}

/**
 * print_hex_upper - prints a hexadecimal number in uppercase
 * @args: argument list containing the hexadecimal number
 *
 * Return: number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, j;

	if (num == 0)
		return (_putchar('0'));
	while (num != 0)
	{
		int remainder = num % 16;
		if (remainder < 10)
			buffer[i] = remainder + '0';
		else
			buffer[i] = remainder + 'A' - 10;
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(buffer[j]);
	return (i);
}
