#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d]\n", len);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("Integer:[%d]\n", 12345);
	_printf("Percent:[%%]\n");
	return (0);
}

