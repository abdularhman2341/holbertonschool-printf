#include "main.h"

/**
 * main - test function for _printf
 *
 * Return: 0
 */
int main(void)
{
	_printf("Hello World\n");
	_printf("Char: %c\n", 'A');
	_printf("String: %s\n", "Holberton");
	_printf("Percent: %%\n");
	_printf("Number: %d\n", 123);
	_printf("Integer: %i\n", -98);
	_printf("Zero: %d\n", 0);

	return (0);
}
