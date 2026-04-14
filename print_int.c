#include "main.h"

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	unsigned int num;
	int count = 0;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_int(num / 10);

	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}
