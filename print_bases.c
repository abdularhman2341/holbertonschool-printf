#include "main.h"

/**
 * print_unsigned - prints an unsigned integer
 * @n: unsigned integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n, char buffer[], int *buff_ind)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10, buffer, buff_ind);
	buffer[(*buff_ind)++] = (n % 10) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_octal - prints an unsigned integer in octal
 * @n: unsigned integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 * Return: number of characters printed
 */
int print_octal(unsigned int n, char buffer[], int *buff_ind)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8, buffer, buff_ind);
	buffer[(*buff_ind)++] = (n % 8) + '0';
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal (lowercase)
 * @n: unsigned integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 * Return: number of characters printed
 */
int print_hex(unsigned int n, char buffer[], int *buff_ind)
{
	int count = 0;
	char *hex_digits = "0123456789abcdef";

	if (n / 16)
		count += print_hex(n / 16, buffer, buff_ind);
	buffer[(*buff_ind)++] = hex_digits[n % 16];
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}

/**
 * print_HEX - prints an unsigned integer in hexadecimal (uppercase)
 * @n: unsigned integer to print
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 * Return: number of characters printed
 */
int print_HEX(unsigned int n, char buffer[], int *buff_ind)
{
	int count = 0;
	char *hex_digits = "0123456789ABCDEF";

	if (n / 16)
		count += print_HEX(n / 16, buffer, buff_ind);
	buffer[(*buff_ind)++] = hex_digits[n % 16];
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	count++;
	return (count);
}
