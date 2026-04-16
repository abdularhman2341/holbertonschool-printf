#include "main.h"

/**
 * print_pointer - prints the value of a pointer variable
 * @p: pointer to print
 * @buffer: buffer array to handle print
 * @buff_ind: current index in buffer
 *
 * Return: number of chars printed
 */
int print_pointer(void *p, char buffer[], int *buff_ind)
{
	int count = 0, i = 0, j;
	unsigned long int num_address;
	char *nil = "(nil)";
	char *hex = "0123456789abcdef";
	char map[20]; /* مصفوفة مؤقتة لتخزين الرقم قبل عكسه */

	if (p == NULL)
	{
		for (j = 0; nil[j] != '\0'; j++)
		{
			buffer[(*buff_ind)++] = nil[j];
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			count++;
		}
		return (count);
	}

	num_address = (unsigned long int)p;

	buffer[(*buff_ind)++] = '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	buffer[(*buff_ind)++] = 'x';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count += 2;

	while (num_address > 0)
	{
		map[i++] = hex[num_address % 16];
		num_address /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[(*buff_ind)++] = map[j];
		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
		count++;
	}

	return (count);
}
