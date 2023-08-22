#include "main.h"
#include <stdlib.h>

/**
 * _printf - Custom printf function.
 * @format: Format string containing directives.
 * @...: Variadic arguments to be printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_int(args);
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				printed_chars++;
			}
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_char - Print a character.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	write(1, str, len);
	return (len);
}

/**
 * print_int - Print an integer.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int num_chars = 0;

	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		num_chars++;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	int temp = num;

	while (temp != 0)
	{
		temp /= 10;
		num_chars++;
	}

	char *buffer = (char *)malloc((num_chars + 1) * sizeof(char));

	if (buffer == NULL)
	{
		return (-1);
	}

	buffer[num_chars] = '\0';

	int i;

	for (i = num_chars - 1; i >= 0; i--)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
	}

	write(1, buffer, num_chars);
	return (num_chars);
}

