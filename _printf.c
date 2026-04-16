#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing the directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0, j;
	char *str;
	char c;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				buffer[buff_ind++] = c;
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++)
				{
					buffer[buff_ind++] = str[j];
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count += print_int(va_arg(args, int), buffer, &buff_ind);
			}
			else if (format[i] == 'b')
			{
				count += print_binary(va_arg(args, unsigned int), buffer, &buff_ind);
			}
			else if (format[i] == 'u')
			{
				count += print_unsigned(va_arg(args, unsigned int), buffer, &buff_ind);
			}
			else if (format[i] == 'o')
			{
				count += print_octal(va_arg(args, unsigned int), buffer, &buff_ind);
			}
			else if (format[i] == 'x')
			{
				count += print_hex(va_arg(args, unsigned int), buffer, &buff_ind);
			}
			else if (format[i] == 'X')
			{
				count += print_HEX(va_arg(args, unsigned int), buffer, &buff_ind);
			}

			else if (format[i] == 'S')
			{
				count += print_custom_string(va_arg(args, char *), buffer, &buff_ind);
			}
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				count++;
			}
			else
			{
				if (format[i] == '\0')
				{
					print_buffer(buffer, &buff_ind); 
					return (-1);
				}
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				buffer[buff_ind++] = format[i];
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				count += 2;
			}
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
