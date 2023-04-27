#include "main.h"

/**
 * print_X - prints an unsigned hexadecimal integer in uppercase letters
 * @args: hexadecimal integer argument
 * Return: number of characters
 */
int print_X(va_list args)
{
	unsigned int num, temp, count = 0;
	char hex[100];
	int i = 0;

	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 55;
		num = num / 16;
		i++;
	}

	while (i--)
		count += _putchar(hex[i]);

	return (count);
}
