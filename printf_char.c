#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_char - a function that prints a char.
 * @val: argument from input
 * Return: 1. Sucess
 **/

int printf_char(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
