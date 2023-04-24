#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void handle_char(va_list args, int *count);
void handle_integer(va_list args, int *count);
void handle_string(va_list args, int *count);

/**
 * my_printf - A simplified implementation of printf
 * @format: The format string
 * Return: The number of characters printed
 */

int my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

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
