#include "main.h"
/**
 * _printf - a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
	{"%s", printf_string}, {"%c", printf_char},
	{"%%", printf_percentage}, {"%i", printf_int},
	{"%d", printf_dec}, {"%r", printf_srev},
	{"%R", printf_rot13},
	{"%b", printf_bin}, {"%u", printf_unsigned},
	{"%o", printf_oct},
	{"%x", printf_hex}, {"%X", printf_HEX},
	{"%S", printf_exclusive_string},
	{"%p", printf_pointer}
	};

	va_list args;
	int x = 0, y, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[x] != '\0')
	{
		y = 13;
		while (y >= 0)
		{
			if (m[y].ch[0] == format[x] && m[y].ch[1] == format[x + 1])
			{
				len += m[y].fh(args);
				x = x + 2;
			}
			y--;
		}
		_putchar(format[x]);
		len++;
		x++;
	}
	va_end(args);
	return (len);
}

