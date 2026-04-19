#include "main.h"

/**
 * print_int - prints an integer
 * @n: integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_int(int n, char buffer[], int *buff_ind)
{
	unsigned int num;
	int count = 0;
	char c;

	if (n < 0)
	{
		c = '-';
		buffer[(*buff_ind)++] = c;
		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_int(num / 10, buffer, buff_ind);

	c = (num % 10) + '0';
	buffer[(*buff_ind)++] = c;
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;

	return (count);
}

