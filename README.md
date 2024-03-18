<h1 align="center">
	<p>
	✏️ ft_printf
	</p>
</h1>

---

## 💡 About the project

> _This project is pretty straight forward. You will recode printf. You will mainly learn how to use variadic arguments._

	This project consists of coding a library that contains a simplified version (more information below) of the printf function.

#### Allowed Function

```c
malloc(), free(), write(), va_start(), va_arg(), va_copy(), va_end()
```

### Mandatory

> <i>A small description of the required conversion:
>
> - `%c` print a single character.
> - `%s` print a string of characters.
> - `%p` The void * pointer argument is printed in hexadecimal.
> - `%d` print a decimal (base 10) number.
> - `%i` print an integer in base 10.
> - `%u` print an unsigned decimal (base 10) number.
> - `%x` print a number in hexadecimal (base 16).
> - `%%` print a percent sign.</i>

---

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library run below given command in your terminal. After successful compilation you will find <b>libftprintf.a</b> file in root directory of the project.

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the ft_printf function in your code, simply include its header:

```C
#include "ft_printf.h"
```

**3. Compile your code**

To compile your code, add <b>libftprintf.a</b> library to compilation command:

```shell
$ gcc file1.c file2.c ... path/to/ft_printf/libftprintf.a
```