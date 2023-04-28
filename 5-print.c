#include "main.h"
#include <stdio.h>
/**
 * print_s - prints a string with
 *	non-printable characters represented in hexadecimal
 * @args: string argument
 * Return: number of characters printed
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
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar("0123456789ABCDEF"[str[i] / 16]);
			count += _putchar("0123456789ABCDEF"[str[i] % 16]);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
