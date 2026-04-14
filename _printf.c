include "main.h"

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

        if (format == NULL)
                return (-1);

        va_start(args, format);
        while (format && format[i])
        {
                if (format[i] != '%')
                {
                        write(1, &format[i], 1);
                        count++;
                }
                else
                {
                        i++;
                        if (format[i] == 'c')
                        {
                                c = va_arg(args, int);
                                write(1, &c, 1);
                                count++;
                        }
                        else if (format[i] == 's')
                        {
                                str = va_arg(args, char *);
                                if (str == NULL)
                                        str = "(null)";
                                for (j = 0; str[j] != '\0'; j++)
                                {
-- INSERT --                                                                                                                                                                                    2,1           Top
