#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_c - prints character
 * @args: character argument
 * Return: number of characters
 */
int print_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (_putchar(c));
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
		_putchar(str[i]);
		i++;
		count++;
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
 * print_d - prints a decimal
 * @args: decimal argument
 * Return: counter
 */
int print_d(va_list args)
{

	unsigned int absolute, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(args, int);
		if (n < 0)
		{
			absolute = (n * -1);
			count += _putchar('-');
		}
		else
			absolute = n;

	aux = absolute;
	countnum = 1;
	while (aux > 9)
	{
		aux /= 10;
		countnum *= 10;
	}
	while (countnum >= 1)
	{
		count += _putchar(((absolute / countnum) % 10) + '0');
		countnum /= 10;
	}
	return (count);
}
/**
 * print_i - prints integer
 * @args: integer argument
 * Return: the decimal function
 */

int print_i(va_list args)
{
	return (print_d(args));
}
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
