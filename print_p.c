#include "main.h"

/**
 * print_p - prints the address of a pointer
 * @args: the pointer to be printed
 *
 * Return: number of characters printed
 */
int print_p(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int addr = (unsigned long int)ptr;
	int printed = 0;

	printed += _putchar('0');
	printed += _putchar('x');
	printed += print_hex(addr);

	return (printed);
}

/**
 * print_hex - prints a hexadecimal number
 * @num: the number to be printed
 *
 * Return: number of characters printed
 */
int print_hex(unsigned long int num)
{
	char hex_digits[] = "0123456789abcdef";
	int printed = 0;

	if (num / 16)
	printed += print_hex(num / 16);

	printed += _putchar(hex_digits[num % 16]);

	return (printed);
}
