#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

int _write_buffer(char c);

int print_char(va_list types);

int print_int(int n);



#endif /* MAIN_H */


