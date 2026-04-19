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

This implementation mimics the behavior of the standard printf function but with a
limited and controlled set of features, making it suitable for learning low-level
programming concepts.

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

## Advanced Conversion Specifiers

### %b (Binary)
Prints an unsigned integer in binary format.

Example:
_printf("%b\n", 5);

Output:
101

---

### %S (Special String)
Prints strings while converting non-printable characters into hexadecimal format.

Example:
_printf("%S\n", "Hi\n");

Output:
Hi\x0A

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

## Buffer System (Advanced)

To improve performance, the program uses a buffer instead of printing characters one by one.

Process:

1. Store characters in a buffer
2. Flush buffer when full
3. Use write() to print in chunks

Benefits:

- Reduces system calls
- Improves performance
- More efficient output handling

---

## Recursion in Integer Printing

The print_int function uses recursion:

Steps:
1. Divide number by 10
2. Call function again
3. Print remainder

Example:
123 → 1 → 2 → 3

This demonstrates understanding of recursion and stack behavior.

---

## Error Handling

The function handles errors safely:

- NULL format string → return -1
- write() failure → return -1
- Invalid specifiers → handled without crashing

---

## Edge Cases

The implementation handles:

- NULL strings
- Negative numbers
- Large integers
- Multiple specifiers

Example:
_printf("%d %d %d\n", 1, -2, 3000);

---

## System Call Usage

The implementation uses the write() system call instead of printf.

Example:
write(1, "Hello", 5);

This provides lower-level control and better understanding of system-level programming.

---

## Modular Design

The project is divided into multiple files:

_printf.c
print_char.c
print_string.c
print_int.c
buffer.c

This makes the code:

- Easy to maintain
- Easy to extend
- More readable

---

## Extensibility

New specifiers can be added easily.

Steps:

1. Create a new function
2. Add it to handler
3. Link it in _printf

Future improvements:

- %u (unsigned int)
- %x (hexadecimal)
- %o (octal)
- %f (floating point)

---

## Performance Notes

Using buffer:

- Faster execution
- Fewer write() calls

Without buffer:

- Slower performance

---

## Memory Efficiency

The program avoids unnecessary memory usage:

- No dynamic allocation
- Uses stack memory
- Efficient execution

---

## Testing Strategy

Test cases include:

_printf("Hello");
_printf("%s", NULL);
_printf("%d", -9999);
_printf("%%");

---

## Comparison with printf

| Feature        | _printf | printf |
|---------------|--------|--------|
| Basic output  | Yes    | Yes    |
| Buffer system | Yes    | Yes    |
| Full features | No     | Yes    |
| Learning tool | High   | Low    |

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

## Compilation

gcc -Wall -Werror -Wextra -pedantic *.c -o printf

---

## Author

Shouq Alqarni
Abdulrahman Alsiri

---
