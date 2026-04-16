# _printf() Function
---

## _printf - formatted output conversion

#include "main.h"
int _printf(const char *format, ...);

---

## Description
The _printf() function prints formatted output based on a format string.  
It writes the result to stdout (standard output stream) and allows multiple values  
to be printed in a clear and organized way.

The function processes the format string step by step. Normal characters are printed  
directly, while special sequences starting with '%' are interpreted as format specifiers  
that determine how the next argument should be displayed.

---

## Format of the format string
The format string is composed of two main parts:

- Ordinary characters → printed exactly as they are  
- Conversion specifiers → introduced by '%'  

Each conversion specifier tells the function how to handle and print the corresponding argument.

---

## Conversion specifiers

| Specifier | Meaning |
|----------|--------|
| d, i     | Prints an integer in decimal format |
| c        | Prints a single character |
| s        | Prints a string |
| %        | Prints a percent sign |

If a NULL string is passed to %s, the function safely prints "(null)".

---

## About Functions

The project is built using a main function and helper functions, where each one has a clear role.

The _printf function is the core of the program. It reads the format string, detects specifiers,  
and decides how each value should be printed.

The print_int function is responsible for printing integers. It handles negative numbers and  
prints digits in the correct order using recursion.

The _write_buffer function manages the output process. It stores characters and writes them  
efficiently to stdout using the write system call.

The print_char function is used to print a single character when the %c specifier is used.

For strings, when %s is detected, the string is printed directly. If the string is NULL,  
the function prints "(null)" instead of causing an error.

---

## Return Value

The _printf() function returns the number of characters printed.  
The null byte is not included in the count.

If an error occurs, the function returns -1.

---

## Examples

#include "main.h"

_printf("Hello world\n");        // Output: Hello world
_printf("%c\n", 'A');           // Output: A
_printf("%s\n", "Holberton");   // Output: Holberton
_printf("%d\n", 123);           // Output: 123
_printf("%i\n", -456);          // Output: -456
_printf("%%\n");                // Output: %

---

## Author

Shouq  
Abdulrahman
