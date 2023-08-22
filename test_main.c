#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("Education is when you read the fine print.\n");
	len2 = _printf("Experience is what you get if you don't\n");

	_printf("Length of the first sentence: %d\n", len1);
	_printf("Length of the second sentence: %d\n", len2);

	return (0);
}

