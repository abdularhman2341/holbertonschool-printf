#include "main.h"

/**
 * print_long - prints a long integer
 * @n: long integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_long(long int n, char buffer[], int *buff_ind)
{
	unsigned long int num;
	int count = 0;

	if (n < 0)
	{
		buffer[(*buff_ind)++] = '-';
		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
		count++;
		num = (unsigned long int)(-n);
	}
	else
	{
		num = (unsigned long int)n;
	}

	if (num / 10)
		count += print_ulong(num / 10, buffer, buff_ind);

	buffer[(*buff_ind)++] = (num % 10) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;

	return (count);
}

/**
 * print_ulong - prints an unsigned long integer
 * @n: unsigned long integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_ulong(unsigned long int n, char buffer[], int *buff_ind)
{
	int count = 0;

	if (n / 10)
		count += print_ulong(n / 10, buffer, buff_ind);
	buffer[(*buff_ind)++] = (n % 10) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_octal_long - prints an unsigned long in octal
 * @n: unsigned long integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_octal_long(unsigned long int n, char buffer[], int *buff_ind)
{
	int count = 0;

	if (n / 8)
		count += print_octal_long(n / 8, buffer, buff_ind);
	buffer[(*buff_ind)++] = (n % 8) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_hex_long - prints an unsigned long in hex (lowercase)
 * @n: unsigned long integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_hex_long(unsigned long int n, char buffer[], int *buff_ind)
{
	int count = 0;
	char *hex_digits = "0123456789abcdef";

	if (n / 16)
		count += print_hex_long(n / 16, buffer, buff_ind);
	buffer[(*buff_ind)++] = hex_digits[n % 16];
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_HEX_long - prints an unsigned long in hex (uppercase)
 * @n: unsigned long integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 * Return: number of characters printed
 */
int print_HEX_long(unsigned long int n, char buffer[], int *buff_ind)
{
	int count = 0;
	char *hex_digits = "0123456789ABCDEF";

	if (n / 16)
		count += print_HEX_long(n / 16, buffer, buff_ind);
	buffer[(*buff_ind)++] = hex_digits[n % 16];
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}
