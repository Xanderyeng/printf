#include "main.h"

/**
 * print_o - prints an unsigned int in octal notation
 * @args: the unsigned int argument
 * Return: number of characters printed
 */
int print_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal[100];
	int i = 0, count = 0;

	if (num == 0)
		return (_putchar('0'));

	while (num != 0)
	{
		octal[i] = num % 8 + '0';
		num /= 8;
		i++;
	}

	octal[i] = '\0';

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(octal[i]);
		count++;
	}

	return (count);
}
