#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints output according to format
 * @format: character string
 * Return: Characters printed
 */

int _printf(const char *format, ...)
{
	int j = 0, k = 0;
	int (*func_ptr)(va_list);
	va_list args;

	va_start(args, format);
	if (format == NULL || !format[j + 1])
	{
		return (-1);
	}
	while (format[j])
	{
		if (format[j] == '%')
		{
			if (format[j + 1])
			{
				if (format[j + 1] != 'c' && format[j + 1] != 's' && format[j + 1] != '%' && format[j + 1] != 'd' && format[j +1] != 'i')
				{
					k += putchar(format[j]);
					k += putchar(format[j + 1]);
					j++;
				}
				else if (format[j + 1] == 'd' || format[j + 1] == 'i')
				{
					func_ptr = printf_decimal;
					k += func_ptr(args);
					j++;
				}
				else
				{
					func_ptr = get_function(&format[j + 1]);
					k += func_ptr(args);
					j++;
				}
			}
		}
		else
		{
			putchar(format[j]);
			k++;
		}
		j++;
	}
	va_end(args);
	return (k);
}
