#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _write_buffer(char c);

int print_char(va_list types);

int print_int(int n, char buffer[], int *buff_ind);

void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */


