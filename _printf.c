#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

void handle_char(va_list args, int *count);
void handle_integer(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_hexadecimal(va_list args, int *count, int uppercase);

/**
 * _printf - A simplified implementation of printf
 * @format: The format string
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					handle_char(args, &count);
					break;
				case 'd':
				case 'i':
					handle_integer(args, &count);
					break;
				case 's':
					handle_string(args, &count);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'x':
					handle_hexadecimal(args, &count, 0);
					break;
				case 'X':
					handle_hexadecimal(args, &count, 1);
					break;
				default:
					putchar(*format);
					count++;
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_char - Handle the %c format specifier
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 */

void handle_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	putchar(c);
	(*count)++;
}

/**
 * handle_integer - Handle the %d and %i format specifiers
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 */

void handle_integer(va_list args, int *count)
{
	int d = va_arg(args, int);

	printf("%d", d);
	(*count) += snprintf(NULL, 0, "%d", d);
}

/**
 * handle_string - Handle the %s format specifier
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 */

void handle_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	printf("%s", s);
	(*count) += strlen(s);
}

/**
 * handle_hexadecimal - Handle the %x and %X format specifiers
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 * @uppercase: A flag indicating whether to use uppercase letters for %X
 */
void handle_hexadecimal(va_list args, int *count, int uppercase)
{
	unsigned int x = va_arg(args, unsigned int);

	if (uppercase)
	{
		printf("%X", x);
		(*count) += snprintf(NULL, 0, "%X", x);
	}
	else
	{
		printf("%x", x);
		(*count) += snprintf(NULL, 0, "%x", x);
	}
}
