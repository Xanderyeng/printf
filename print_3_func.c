#include "main.h"

/**
 * print_u - print an unsigned integer
 * @args: argument list containing the unsigned integer to print
 * Return: number of characters printed
 */
int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[10];
	int count = 0;
	int i;

	if (n == 0)
	return (_putchar('0'));

	for (i = 0; n != 0; i++)
	{
		buffer[i] = n % 10 + '0';
		n /= 10;
	}

	for (i--; i >= 0; i--)
	{
		count += _putchar(buffer[i]);
	}

	return (count);
}
