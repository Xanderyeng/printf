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
/**
 * print_o - prints an octal number
 * @args: decimal argument
 * Return: counter
 */
int print_o(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int count = 0;
	unsigned int octal_num[100];
	unsigned int i = 0;

	while (n > 0)
	{
		octal_num[i] = n % 8;
		n /= 8;
		i++;
	}

	if (i == 0)
	{
		count += _putchar('0');
		return (count);
	}

	for (i--; i < 100; i--)
	{
		count += _putchar(octal_num[i] + '0');
		if (i == 0)
		break;
	}

	return (count);
}
