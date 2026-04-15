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
	int count = 0;
	int i = 0;
	int j;
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
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				count++;
			}
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (count);
}


void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
