#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print_format - structure to match a format specifier with a function
 * @spec: the format specifier
 * @f: the function to handle the format specifier
 *
 * Return: void
 */
typedef struct print_format
{
	char *spec;
	void (*f)(va_list args, int *count);
} print_format_t;

int _putchar(char c);
int _printf(const char *format, ...);
int handle_print(const char *fmt, va_list args, int *count);
void handle_char(va_list args, int *count);
void handle_integer(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_hexadecimal(va_list args, int *count, int uppercase);
void handle_unknown(int *count, char spec);
void handle_octal(va_list args, int *count);
void handle_pointer(va_list args, int *count);
void handle_unsigned(va_list args, int *count);
void handle_S(va_list args, int *count);

#endif /* MAIN_H */
