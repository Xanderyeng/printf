#include "main.h"

/**
 * print_x - prints a hexadecimal
 * @args: hexadecimal argument
 * Return: counter
 */
int print_x(va_list args)
{
	unsigned int n;
	char hex[100];
	int i, j, count = 0;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}
	i = 0;
	while (n > 0)
	{
		int rem = n % 16;

		if (rem < 10)
			hex[i] = 48 + rem;
		else
			hex[i] = 87 + rem;
		n /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		count += _putchar(hex[j]);
	return (count);
}

