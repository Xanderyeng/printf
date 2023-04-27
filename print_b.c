#include "main.h"

/**
 * print_b - prints a decimal in binary form
 * @args: decimal argument
 * Return: number of characters printed
 */
int print_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	int binary[32];
	int i = 0;

	if (n == 0)
	{
		return (_putchar('0'));
	}

	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		count += _putchar(binary[i] + '0');
	}

	return (count);
}
