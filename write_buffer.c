#include "main.h"

/**
 * _write_buffer - Accumulates characters in a 1024-byte buffer.
 * @c: The character to add to the buffer.
 *
 * Return: 1 on success.
 */
int _write_buffer(char c)
{
	static char buffer[1024];
	static int i;

	if (i == 1024)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	else if (i > 0)
	{
		write(1, buffer, i);
		i = 0;
	}

	return (1);
}
