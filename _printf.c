#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <limits.h>

void handle_char(va_list args, int *count);
void handle_integer(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_hexadecimal(va_list args, int *count, int uppercase);
void handle_unknown(int *count, char spec);
void handle_octal(va_list args, int *count);
void handle_pointer(va_list args, int *count);
void handle_unsigned(va_list args, int *count);
void print_hex(unsigned int num, int *count);
void handle_binary(va_list args, int *count);

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
			_putchar(*format);
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
				case 'u':
					handle_unsigned(args, &count);
					break;
				case 's':
					handle_string(args, &count);
					break;
				case 'x':
					handle_hexadecimal(args, &count, 0);
					break;
				case 'X':
					handle_hexadecimal(args, &count, 1);
					break;
				case 'p':
					handle_pointer(args, &count);
					break;
				case 'o':
					handle_octal(args, &count);
					break;
				case 'b':
					handle_binary(args, &count);
					break;
				case 'S':
					handle_S(args, &count);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					handle_unknown(&count, *format);
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_binary - Converts unsigned int to binary
 * @args: A va_list pointing to the next unsigned int argument
 * @count: A pointer to the count of characters printed so far
 *
 * Return: void
 */

void handle_binary(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int mask = 1 << ((sizeof(unsigned int) * CHAR_BIT) - 1);
	int printed = 0;

	while (mask > 0)
	{
		if ((num & mask) == mask)
	{
		_putchar('1');
		printed++;
	}
	else if (printed)
	{
		_putchar('0');
		printed++;
	}
		mask >>= 1;
	}
	if (!printed)
	{
		_putchar('0');
		printed++;
	}
		*count += printed;
}

/**
 * handle_S - Handles the custom conversion specifier %S
 * @args: The va_list containing the next argument
 * @count: A pointer to the character count
 */

void handle_S(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
	{
		printf("(null)");
		*count += 6;
		return;
	}

	while (str[i] != '\0')
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			print_hex(str[i], count);
		}
		else
		{
			_putchar(str[i]);
			*count += 1;
		}
		i++;
	}
}

/**
 * handle_char - Handle the %c format specifier
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 */

void handle_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	_putchar(c);
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

/**
 * handle_unknown - Handle any unknown format specifier
 *	args A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 * @spec: spec
 */

void handle_unknown(int *count, char spec)
{
	_putchar('%');
	_putchar(spec);
	(*count) += 2;
}

/**
 * handle_address - Handle the %p format specifier
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 *
 */

void handle_address(va_list args, int *count)
{
	void *p = va_arg(args, void *);

	printf("%p", p);
	(*count) += snprintf(NULL, 0, "%p", p);
}

/**
 * handle_pointer - handling pointers
 * @args: va_list
 * @count: count of the pointer(s)
 *
 */

void handle_pointer(va_list args, int *count)
{
	void *p = va_arg(args, void *);

	printf("%p", p);
	(*count) += snprintf(NULL, 0, "%p", p);
}

/**
 * handle_octal - handling octal values
 * @args: va_list
 * @count: count of the octal values
 *
 */

void handle_octal(va_list args, int *count)
{
	unsigned int u = va_arg(args, unsigned int);

	printf("%o", u);
	(*count) += snprintf(NULL, 0, "%o", u);
}

/**
 * handle_unsigned - Handle the %u and %d format specifiers
 * @args: A va_list containing the arguments to the function
 * @count: A pointer to the count of printed characters
 */
void handle_unsigned(va_list args, int *count)
{
	unsigned int u = va_arg(args, int);

	printf("%u", u);
	(*count) += snprintf(NULL, 0, "%u", u);
}


/**
 * print_hex - print ASCII code value of hexadecimal
 * @num: value
 * @count: value
 */

void print_hex(unsigned int num, int *count)
{
	char *hex_chars = "0123456789ABCDEF";

	int i, j, remainder;
	char hex[100];

	i = 0;
	while (num != 0)
	{
		remainder = num % 16;
		hex[i] = hex_chars[remainder];
		num = num / 16;
		i++;
	}
	if (i == 0)
	{
		_putchar('0');
		(*count)++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
	{
		_putchar(hex[j]);
		(*count)++;
		}
	}
}
