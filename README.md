# _printf()

> A custom implementation of the standard C function `printf`, built from scratch
> using low-level system calls, buffer optimization, and modular architecture.

---

## Overview

`_printf` recreates the behavior of the standard `printf` function.

It converts formatted input into output written to `stdout`.

This project focuses on:
- Understanding internal mechanics of formatted output
- Controlling memory and execution flow
- Building a modular and extensible system

---

## Why This Project Matters

Instead of using `printf`, this project shows:
- How arguments are passed dynamically
- How format strings are interpreted
- How output is generated at system level

This is essential for:
- Systems programming
- Debugging low-level applications
- Cybersecurity (memory + control flow awareness)

---

## Core Features

| Feature          | Description                |
|-----------------|--------------------------|
| %c              | Character                 |
| %s              | String                    |
| %d / %i         | Integer                   |
| %%              | Percent sign              |

---

## Advanced Features

### Binary (%b)

Converts integer to binary.

```c
_printf("%b\n", 5);
```

Output:
```
101
```

---

### Special String (%S)

Non-printable characters are converted to hex.

```c
_printf("%S\n", "Hi\n");
```

Output:
```
Hi\x0A
```

---

## Internal Architecture (UML Style)

```
+------------------+
|     _printf      |
+------------------+
         |
         v
+------------------+
| Format Parser    |
+------------------+
         |
   -------------------
   |   |   |   |    |
   v   v   v   v    v
  %c  %s  %d  %b   %S
   |   |   |   |    |
   v   v   v   v    v
 print handlers
         |
         v
+------------------+
| Buffer Manager   |
+------------------+
         |
         v
      write()
```

---

## Execution Flow (Detailed)

Example:
```c
_printf("Value: %d", 10);
```

### Step-by-step:

1. Read 'V' → print  
2. Read 'a' → print  
3. Continue...  
4. Read '%' → special case  
5. Next char 'd' → integer handler  
6. Call `print_int(10)`  
7. Convert → '1' '0'  
8. Add to buffer  
9. Flush buffer  

Final Output:
```
Value: 10
```

---

## Parsing Logic (Pseudo Code)

```
for each character in format:
    if character != '%':
        print character
    else:
        next = next character
        find matching function
        call function
```

---

## Variadic Function Internals

```
va_list args;
va_start(args, format);

value = va_arg(args, int);

va_end(args);
```

### What happens internally:

- Arguments stored in stack
- va_arg retrieves them sequentially
- Order matters strictly

---

## Memory & Stack Behavior

When calling:

```c
_printf("%d %c", 10, 'A');
```

Stack layout (simplified):

```
| 'A'        |
| 10         |
| format ptr |
```

va_arg reads:
1. 10
2. 'A'

---

## Buffer System (Deep Explanation)

Instead of:

```
write(1, &c, 1);
```

We use:

```
buffer[index++] = c;
```

When full:

```
write(1, buffer, size);
index = 0;
```

### Why this matters:

- Reduces system calls
- Improves performance
- Mimics real-world libraries

---

## Integer Printing (Recursion Explained)

For `123`:

```
print(123)
 → print(12)
   → print(1)
     → print '1'
   → print '2'
 → print '3'
```

This ensures correct order.

---

## Binary Conversion Logic

```
while (n > 0):
    remainder = n % 2
    store remainder
    n = n / 2
reverse output
```

---

## Special String Logic

```
if ASCII < 32 OR ASCII >= 127:
    print "\x"
    print hex value
else:
    print character
```

---

## Error Handling

| Case              | Behavior        |
|------------------|----------------|
| NULL format       | return -1      |
| write failure     | return -1      |
| unknown specifier | safe handling  |

---

## Edge Cases

- Empty string
- NULL pointer
- Large integers
- Negative numbers
- Multiple specifiers

---

## Complexity Analysis

### Time
```
O(n)
```

### Space
```
O(1)
```

---

## Extensibility Design

Handler structure:

```c
struct specifier {
    char spec;
    int (*func)(va_list);
};
```

Adding new specifier:
1. Create function
2. Add to struct
3. Link in parser

---

## Testing Strategy

### Functional Tests
```
_printf("Hello");
_printf("%d", 0);
```

### Edge Tests
```
_printf("%s", NULL);
_printf("%d", -9999);
```

### Stress Tests
```
_printf("Long long long string...");
```

---

## Debugging Strategy

- Trace format parsing
- Check buffer contents
- Validate recursion output

---

## Security Perspective (Important)

This project relates to cybersecurity:

### Risks:
- Buffer overflow
- Invalid memory access
- Format string vulnerabilities

### Protection:
- Controlled buffer
- Input validation
- Safe NULL handling

---

## Comparison with Standard printf

| Feature        | _printf | printf |
|---------------|--------|--------|
| Basic output  | Yes    | Yes    |
| Buffering     | Yes    | Yes    |
| Floating      | No     | Yes    |
| Flags         | No     | Yes    |

---

## Limitations

- No floating-point support
- No width/precision
- No flags
- Limited specifiers

---

## Future Improvements

- Add `%x`, `%o`, `%u`
- Add `%f`
- Support width & precision
- Dynamic buffer resizing

---

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic *.c -o printf
```

---

## Usage

```bash
./printf
```

---

## Authors

**Shouq Alqarni**  
**Abdulrahman Alsiri**
