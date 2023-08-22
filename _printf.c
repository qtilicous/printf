#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to write
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer recursively
 * @n: The integer to print
 * Return: The number of digits printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	_putchar(n % 10 + '0');
	return (count + 1);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

