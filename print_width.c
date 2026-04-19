#include "main.h"

/**
 * count_digits - counts digits of an unsigned long in a given base
 * @n: number
 * @base: base (10, 8, 16)
 *
 * Return: number of digits
 */
int count_digits(unsigned long int n, int base)
{
	int count = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

/**
 * pad_spaces - writes n spaces to the buffer
 * @n: number of spaces to write
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int pad_spaces(int n, char buffer[], int *buff_ind)
{
	int i;

	for (i = 0; i < n; i++)
	{
		buffer[(*buff_ind)++] = ' ';
		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
	}
	return (n);
}

