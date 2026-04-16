#include "main.h"

/**
 * print_binary - prints an unsigned integer in binary
 * @n: unsigned integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n, char buffer[], int *buff_ind)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2, buffer, buff_ind);

	buffer[(*buff_ind)++] = (n % 2) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;

	return (count);
}
