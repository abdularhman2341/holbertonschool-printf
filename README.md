_printf() Function

_printf - formatted output conversion

#include "main.h"
int _printf(const char *format, ...);

Description
The _printf() function prints output based on a format string.
It writes the output to stdout (standard output).

The function processes the format string and prints each part accordingly.
It supports variadic arguments, meaning it can accept multiple values after the format string.

Format of the format string
The format string consists of:
- Normal characters, which are printed as they are
- Format specifiers, which start with '%'

Each format specifier tells the function how to handle and print the next argument.

Conversion specifiers
The supported format specifiers are:

d, i:
Prints an integer in decimal format.

c:
Prints a single character.

s:
Prints a string.
If the string is NULL, "(null)" is printed instead.

%:
Prints a percent sign.

About Functions

int _printf(const char *format, ...)
The main function that reads the format string and controls the printing process.

int print_int(int n)
Handles integer printing for %d and %i.
It prints numbers digit by digit and supports negative values.

int _write_buffer(char c)
Stores characters in a buffer and writes them to stdout.
This helps make the output process more efficient.

int print_char(char c)
Prints a single character when %c is used.

String handling
When %s is used, the function prints the string directly.
If a NULL pointer is passed, it safely prints "(null)".

Return Value
The _printf() function returns the number of characters printed.
The null byte is not included in the count.

If an error occurs, the function returns -1.

Examples

#include "main.h"

_printf("Hello world\n");        // Output: Hello world
_printf("%c\n", 'A');           // Output: A
_printf("%s\n", "Holberton");   // Output: Holberton
_printf("%d\n", 123);           // Output: 123
_printf("%i\n", -456);          // Output: -456
_printf("%%\n");                // Output: %

Author

Shouq
Abdulrahman
