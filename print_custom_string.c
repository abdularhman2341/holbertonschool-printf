#include "main.h"

/**
 * print_custom_string - Prints a string, non-printable characters
 * are printed this way: \x, followed by the ASCII code value in hex.
 * @str: the string to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_custom_string(char *str, char buffer[], int *buff_ind)
{
	int i = 0, count = 0;
	char *hex = "0123456789ABCDEF";
	unsigned char c;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 32 && c < 127)
		{
			buffer[(*buff_ind)++] = c;
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			count++;
		}
		else
		{
			buffer[(*buff_ind)++] = '\\';
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			buffer[(*buff_ind)++] = 'x';
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			buffer[(*buff_ind)++] = hex[c / 16]; /* الخانة الأولى */
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			buffer[(*buff_ind)++] = hex[c % 16]; /* الخانة الثانية */
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			count += 4;
		}
		i++;
	}
	return (count);
}
