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
	int flag_plus, flag_space, flag_hash;
	int n;
	unsigned int un;
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
			flag_plus = 0;
			flag_space = 0;
			flag_hash = 0;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					flag_plus = 1;
				else if (format[i] == ' ')
					flag_space = 1;
				else
					flag_hash = 1;
				i++;
			}
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
				n = va_arg(args, int);
				if (n >= 0)
				{
					if (flag_plus)
					{
						buffer[buff_ind++] = '+';
						if (buff_ind == BUFF_SIZE)
							print_buffer(buffer, &buff_ind);
						count++;
					}
					else if (flag_space)
					{
						buffer[buff_ind++] = ' ';
						if (buff_ind == BUFF_SIZE)
							print_buffer(buffer, &buff_ind);
						count++;
					}
				}
				count += print_int(n, buffer, &buff_ind);
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
				un = va_arg(args, unsigned int);
				if (flag_hash && un != 0)
				{
					buffer[buff_ind++] = '0';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
				}
				count += print_octal(un, buffer, &buff_ind);
			}
			else if (format[i] == 'x')
			{
				un = va_arg(args, unsigned int);
				if (flag_hash && un != 0)
				{
					buffer[buff_ind++] = '0';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
					buffer[buff_ind++] = 'x';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
				}
				count += print_hex(un, buffer, &buff_ind);
			}
			else if (format[i] == 'X')
			{
				un = va_arg(args, unsigned int);
				if (flag_hash && un != 0)
				{
					buffer[buff_ind++] = '0';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
					buffer[buff_ind++] = 'X';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
				}
				count += print_HEX(un, buffer, &buff_ind);
			}
			else if (format[i] == 'S')
			{
				count += print_custom_string(va_arg(args, char *), buffer, &buff_ind);
			}
			else if (format[i] == 'p')
			{
				count += print_pointer(va_arg(args, void *), buffer, &buff_ind);
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
