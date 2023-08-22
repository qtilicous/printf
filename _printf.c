#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: 1 (success), -1 (failure)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Handles 'c' conversion specifier
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Handles 's' conversion specifier
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * print_number - Handles 'd' and 'i' conversion specifiers
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	int temp = num;
	int digits = 0;
	int count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	do {
		temp /= 10;
		digits++;
	} while (temp != 0);

	temp = num;
	while (digits > 0)
	{
		char digit = (temp / digits) + '0';

		count += _putchar(digit);
		temp %= digits;
		digits /= 10;
	}

	return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *c;

	va_start(args, format);
	for (c = format; *c != '\0'; c++)
	{
		if (*c != '%')
		{
			count += _putchar(*c);
		}
		else
		{
			c++;
			if (*c == 'c')
				count += print_char(args);
			else if (*c == 's')
				count += print_string(args);
			else if (*c == '%')
				count += _putchar('%');
			else if (*c == 'd' || *c == 'i')
				count += print_number(args);
			else
			{
				count += _putchar('%');
				count += _putchar(*c);
			}
		}
	}
	va_end(args);

	return (count);
}

