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
	int len_long, len_short;
	int width, out_len;
	long int ln;
	unsigned long int uln;
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
			width = 0;
			if (format[i] == '*')
			{
				width = va_arg(args, int);
				if (width < 0)
					width = 0;
				i++;
			}
			else
			{
				while (format[i] >= '0' && format[i] <= '9')
				{
					width = width * 10 + (format[i] - '0');
					i++;
				}
			}
			len_long = 0;
			len_short = 0;
			if (format[i] == 'l')
			{
				len_long = 1;
				i++;
			}
			else if (format[i] == 'h')
			{
				len_short = 1;
				i++;
			}
			if (format[i] == 'c')
			{
				if (width > 1)
					count += pad_spaces(width - 1, buffer, &buff_ind);
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
					;
				if (width > j)
					count += pad_spaces(width - j, buffer, &buff_ind);
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
				if (len_long)
					ln = va_arg(args, long int);
				else if (len_short)
					ln = (short int)va_arg(args, int);
				else
					ln = va_arg(args, int);
				if (ln < 0)
					out_len = count_digits((unsigned long int)(-ln), 10) + 1;
				else if (flag_plus || flag_space)
					out_len = count_digits((unsigned long int)ln, 10) + 1;
				else
					out_len = count_digits((unsigned long int)ln, 10);
				if (width > out_len)
					count += pad_spaces(width - out_len, buffer, &buff_ind);
				if (ln >= 0)
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
				if (len_long || len_short)
					count += print_long(ln, buffer, &buff_ind);
				else
					count += print_int((int)ln, buffer, &buff_ind);
			}
			else if (format[i] == 'b')
			{
				count += print_binary(va_arg(args, unsigned int), buffer, &buff_ind);
			}
			else if (format[i] == 'u')
			{
				if (len_long)
					uln = va_arg(args, unsigned long int);
				else if (len_short)
					uln = (unsigned short int)va_arg(args, unsigned int);
				else
					uln = va_arg(args, unsigned int);
				out_len = count_digits(uln, 10);
				if (width > out_len)
					count += pad_spaces(width - out_len, buffer, &buff_ind);
				if (len_long || len_short)
					count += print_ulong(uln, buffer, &buff_ind);
				else
					count += print_unsigned((unsigned int)uln, buffer, &buff_ind);
			}
			else if (format[i] == 'o')
			{
				if (len_long)
					uln = va_arg(args, unsigned long int);
				else if (len_short)
					uln = (unsigned short int)va_arg(args, unsigned int);
				else
					uln = va_arg(args, unsigned int);
				out_len = count_digits(uln, 8);
				if (flag_hash && uln != 0)
					out_len++;
				if (width > out_len)
					count += pad_spaces(width - out_len, buffer, &buff_ind);
				if (flag_hash && uln != 0)
				{
					buffer[buff_ind++] = '0';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					count++;
				}
				if (len_long || len_short)
					count += print_octal_long(uln, buffer, &buff_ind);
				else
					count += print_octal((unsigned int)uln, buffer, &buff_ind);
			}
			else if (format[i] == 'x')
			{
				if (len_long)
					uln = va_arg(args, unsigned long int);
				else if (len_short)
					uln = (unsigned short int)va_arg(args, unsigned int);
				else
					uln = va_arg(args, unsigned int);
				out_len = count_digits(uln, 16);
				if (flag_hash && uln != 0)
					out_len += 2;
				if (width > out_len)
					count += pad_spaces(width - out_len, buffer, &buff_ind);
				if (flag_hash && uln != 0)
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
				if (len_long || len_short)
					count += print_hex_long(uln, buffer, &buff_ind);
				else
					count += print_hex((unsigned int)uln, buffer, &buff_ind);
			}
			else if (format[i] == 'X')
			{
				if (len_long)
					uln = va_arg(args, unsigned long int);
				else if (len_short)
					uln = (unsigned short int)va_arg(args, unsigned int);
				else
					uln = va_arg(args, unsigned int);
				out_len = count_digits(uln, 16);
				if (flag_hash && uln != 0)
					out_len += 2;
				if (width > out_len)
					count += pad_spaces(width - out_len, buffer, &buff_ind);
				if (flag_hash && uln != 0)
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
				if (len_long || len_short)
					count += print_HEX_long(uln, buffer, &buff_ind);
				else
					count += print_HEX((unsigned int)uln, buffer, &buff_ind);
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
