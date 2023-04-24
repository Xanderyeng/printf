#include "main.h"
#indluce <stdio.h>
#include <stdarg.h>

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *str, *sub;
	unsigned int i = 0, j = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			sub = switch_specifier(*(format + (i + 1)), args);
			if (sub != NULL)
			{
				str = sub;
				while (*(str + j))
				{
					_putchar(*(str + j));
					count++;
					j++;
				}
				j = 0;
				i += 2;
				free(sub);
				continue;
			}
			else if (*(format + (i + 1)) == '%')
			{
				_putchar('%');
				count++;
				i += 2;
				continue;
			}
			else if (*(format + (i + 1)) == '\0')
				return (-1);
		}
		_putchar(*(format + i));
		count++;
		i++;
	}
	va_end(args);

	return (count);
}

/**
 * switch_specifier - Switches to the right conversion function
 * @specifier: The format specifier to check.
 * @args: A va_list of arguments to parse.
 *
 * Return: The converted string.
 */
char *switch_specifier(char specifier, va_list args)
{
	char *res;

	switch (specifier)
	{
		case 'c':
			res = convert_char(va_arg(args, int));
			break;
		case 's':
			res = convert_string(va_arg(args, char *));
			break;
		default:
			res = NULL;
			break;
	}

	return (res);
}

/**
 * convert_char - Converts a char to a string.
 * @c: The character to convert.
 *
 * Return: The converted string.
 */
char *convert_char(char c)
{
	char *str = malloc(sizeof(char) * 2);

	if (str == NULL)
		return (NULL);

	*str = c;
	*(str + 1) = '\0';

	return (str);
}

/**
 * convert_string - Converts a string to a string.
 * @s: The string to convert.
 *
 * Return: The converted string.
 */
char *convert_string(char *s)
{
	char *str, *tmp;
	unsigned int len;

	if (s == NULL)
	{
		str = malloc(sizeof(char) * 7);
		if (str == NULL)
			return (NULL);
		str = "(null)";
		return (str);
	}

	len = _strlen(s);
	tmp = malloc(sizeof(char) * len + 1);
	if (tmp == NULL)
		return (NULL);
	str = tmp;

	while (*s)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';

	return (str);
}

/**
 * _strlen - Gets the length of a string.
 * @s: The string to check.
 *
 * Return: The length of the string.
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}

