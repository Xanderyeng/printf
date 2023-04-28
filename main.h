#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

spec arr[] = {
    {"c", print_c},
    {"s", print_s},
    {"%", print_percent},
    {"d", print_d},
    {"i", print_i},
    {"p", print_p}, /* add this line */
    {NULL, NULL}
};
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_p(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_b(va_list args);
int print_S(va_list args);

#endif
