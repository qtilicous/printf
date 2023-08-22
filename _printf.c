#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

/**
 * _printf - Custom printf function with limited format specifiers
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);

	for (i = 0; format && format[i]; ++i)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			++count;
		}
		else
		{
			switch (format[i + 1])
			{
				default:
					break;
			}
			++i;
		}
	}

	va_end(args);
	return (count);
}

