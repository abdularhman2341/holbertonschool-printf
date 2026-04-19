# =============================================================================
#                           _PRINTF() FULL DOCUMENTATION
# =============================================================================

# NAME
# -----------------------------------------------------------------------------
# _printf - custom formatted output conversion function

# SYNOPSIS
# -----------------------------------------------------------------------------
#   #include "main.h"
#   int _printf(const char *format, ...);

# OVERVIEW
# -----------------------------------------------------------------------------
#   _printf is a custom implementation of the standard printf function.
#   It produces formatted output and writes it to the standard output stream.
#
#   This implementation focuses on:
#       - Understanding variadic functions
#       - Low-level output handling (write system call)
#       - Modular and extensible design
#       - Efficient buffering strategies
#
#   It supports a limited but expandable set of format specifiers.

# DESIGN GOALS
# -----------------------------------------------------------------------------
#   1. Simplicity → easy to understand structure
#   2. Modularity → separated logic per functionality
#   3. Efficiency → reduced system calls using buffering
#   4. Safety → handling NULL pointers and edge cases
#   5. Extensibility → easy addition of new specifiers

# FORMAT STRING STRUCTURE
# -----------------------------------------------------------------------------
#   The format string consists of:
#
#   [1] Literal Characters
#       Printed directly without modification
#
#   [2] Conversion Specifiers
#       Begin with '%' and modify how arguments are printed
#
#   Example:
#       "Hello %s, number %d"
#
#   Processing Steps:
#       - Read character
#       - If not '%': print directly
#       - If '%': parse next character
#       - Call appropriate handler

# SUPPORTED SPECIFIERS (CORE)
# -----------------------------------------------------------------------------
#   %c      → character
#   %s      → string
#   %d      → integer (decimal)
#   %i      → integer (decimal)
#   %%      → percent symbol

# EXTENDED / ADVANCED SPECIFIERS
# -----------------------------------------------------------------------------
#   %b      → binary representation of unsigned int
#   %S      → string with non-printable characters converted to hex

# INTERNAL ARCHITECTURE
# -----------------------------------------------------------------------------
#   The system is composed of:
#
#   +-------------------+
#   |     _printf       |
#   +-------------------+
#            |
#            v
#   +-------------------+
#   | Specifier Parser  |
#   +-------------------+
#            |
#   -----------------------------
#   |       |        |          |
#   v       v        v          v
# print_c  print_s  print_d   others
#
#            |
#            v
#   +-------------------+
#   | Buffer Manager    |
#   +-------------------+
#            |
#            v
#         write()

# VARIADIC FUNCTION MECHANISM
# -----------------------------------------------------------------------------
#   _printf uses <stdarg.h>:
#
#   va_list args;
#   va_start(args, format);
#
#   Each specifier:
#       va_arg(args, type)
#
#   va_end(args);

# CHARACTER OUTPUT HANDLING
# -----------------------------------------------------------------------------
#   Characters are NOT written directly each time.
#
#   Instead:
#       - Stored in buffer
#       - Flushed when needed
#
#   This reduces system calls:
#       write() is expensive
#
#   Buffer Example:
#       char buffer[1024];
#       int index;

# BUFFER MANAGEMENT STRATEGY
# -----------------------------------------------------------------------------
#   1. Add characters to buffer
#   2. If buffer full:
#           flush using write()
#   3. Continue writing
#
#   Advantages:
#       - Performance improvement
#       - Reduced kernel interaction

# INTEGER PRINTING (DETAILED)
# -----------------------------------------------------------------------------
#   Steps:
#
#   1. Detect sign
#   2. Convert negative to positive
#   3. Recursively print digits
#
#   Example:
#       Input: -123
#
#       Output Flow:
#           '-'
#           print(1)
#           print(2)
#           print(3)
#
#   Recursion Tree:
#       123
#       └── 12
#           └── 1

# BINARY CONVERSION (%b)
# -----------------------------------------------------------------------------
#   Algorithm:
#
#   while (n > 0):
#       remainder = n % 2
#       store remainder
#       n = n / 2
#
#   Print in reverse order
#
#   Example:
#       5 → 101

# SPECIAL STRING (%S)
# -----------------------------------------------------------------------------
#   Rules:
#
#   if ASCII < 32 OR >= 127:
#       print as \xHH
#
#   else:
#       print normally
#
#   Example:
#       "A\n" → A\x0A

# ERROR HANDLING
# -----------------------------------------------------------------------------
#   Cases handled:
#
#   1. format == NULL
#       return -1
#
#   2. write() failure
#       return -1
#
#   3. Unknown specifier
#       print as-is OR ignore

# EDGE CASES
# -----------------------------------------------------------------------------
#   _printf("")
#   _printf(NULL)
#   _printf("%")
#   _printf("%s", NULL)
#   _printf("%d", INT_MIN)

# TIME COMPLEXITY
# -----------------------------------------------------------------------------
#   O(n)
#
#   Where n = length of format string

# SPACE COMPLEXITY
# -----------------------------------------------------------------------------
#   O(1)
#
#   Fixed buffer size

# RECURSION DEPTH
# -----------------------------------------------------------------------------
#   Depends on digits count:
#
#   max for int:
#       10 calls (32-bit int)

# EXTENSIBILITY DESIGN
# -----------------------------------------------------------------------------
#   Specifiers handled using:
#
#   struct format_handler {
#       char spec;
#       int (*func)(va_list);
#   };
#
#   Adding new specifier:
#       - define function
#       - add to array

# FILE STRUCTURE
# -----------------------------------------------------------------------------
#   main.h
#   _printf.c
#   handlers.c
#   buffer.c
#   utils.c

# COMPILATION
# -----------------------------------------------------------------------------
#   gcc -Wall -Wextra -Werror -pedantic *.c -o printf

# USAGE
# -----------------------------------------------------------------------------
#   ./printf

# EXAMPLES (DETAILED)
# -----------------------------------------------------------------------------
#   _printf("Hello\n");
#   _printf("%c\n", 'A');
#   _printf("%s\n", "Test");
#   _printf("%d\n", 100);
#   _printf("%i\n", -20);
#   _printf("%b\n", 7);
#   _printf("%S\n", "Hi\n");
#   _printf("%%\n");

# SAMPLE OUTPUT TRACE
# -----------------------------------------------------------------------------
#   Input:
#       "Value: %d"
#
#   Steps:
#       'V' → print
#       'a' → print
#       ...
#       '%' → detect
#       'd' → call print_int
#
#   Output:
#       Value: 10

# COMPARISON WITH STANDARD printf
# -----------------------------------------------------------------------------
#   Feature              _printf      printf
#   -----------------------------------------
#   Basic Output         YES          YES
#   Buffering            YES          YES
#   Floating Point       NO           YES
#   Width/Precision      NO           YES
#   Learning Value       HIGH         LOW

# TESTING PLAN
# -----------------------------------------------------------------------------
#   Categories:
#
#   1. Functional tests
#   2. Boundary tests
#   3. Stress tests
#
#   Examples:
#       _printf("%d", 0);
#       _printf("%d", -999999);
#       _printf("%s", "");
#       _printf("%c", 'Z');

# DEBUGGING STRATEGY
# -----------------------------------------------------------------------------
#   - Print intermediate values
#   - Check buffer state
#   - Validate recursion output

# LIMITATIONS
# -----------------------------------------------------------------------------
#   Does NOT support:
#
#   - floating points (%f)
#   - width/precision
#   - flags
#   - scientific notation

# FUTURE IMPROVEMENTS
# -----------------------------------------------------------------------------
#   - add %x, %o, %u
#   - support flags
#   - support floating point
#   - dynamic buffer

# SECURITY CONSIDERATIONS
# -----------------------------------------------------------------------------
#   - avoid buffer overflow
#   - validate pointers
#   - limit recursion depth

# BEST PRACTICES USED
# -----------------------------------------------------------------------------
#   - modular code
#   - clear naming
#   - separation of concerns
#   - efficient I/O

# AUTHOR
# -----------------------------------------------------------------------------
#   Shouq Alqarni
#   Abdulrahman Alsiri

# END OF DOCUMENT
# =============================================================================
