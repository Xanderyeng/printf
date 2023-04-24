#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that produces output
 * according to a format
 *
 * @format: an array ( s, c,%)
 *
 * Return: success
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%')
	{
		i++;
		switch (format[i])
		{
		case 'c':
			count += putchar(va_arg(args, int));
			break;
		case 's':
			count += _print_str(va_arg(args, char *));
		break;
		case '%':
			count += putchar('%');
			break;
		default:
			count += putchar('%');
			count += putchar(format[i]);
			break;
			}
		}
		else
		{
			count += putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}

/**
 * _print_str - prints a string to stdout
 * @str: the string to print
 *
 * Return: the number of characters printed
 *
 */

int _print_str(char *str)
{
	int i, count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		count += putchar(str[i]);
	}

	return (count);
}
