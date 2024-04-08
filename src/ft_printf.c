/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 12:54:06 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Prints a variable argument according to the provided format specifier.
 *
 * This function takes a format specifier `c` and a variable argument list `valist`
 * and prints the corresponding value according to the specified format. The supported
 * format specifiers are:
 *
 * - 'c': Print a character.
 * - 's': Print a null-terminated string.
 * - 'p': Print a pointer in hexadecimal format with '0x' prefix. Outputs "(nil)" if the pointer is NULL.
 * - 'd' or 'i': Print a decimal integer.
 * - 'u': Print an unsigned integer.
 * - 'x': Print an unsigned integer in lowercase hexadecimal format.
 * - 'X': Print an unsigned integer in uppercase hexadecimal format.
 * - '%': Print a percent sign.
 *
 * @param c The format specifier indicating the type of variable argument to be printed.
 * @param valist The variable argument list containing the value to be printed.
 *
 * @return Upon successful completion, the function returns the number of characters printed.
 * If an output error is encountered, a negative value is returned.
 */
static int ft_print_var(char c, va_list valist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(valist, int))); // Print a character
	else if (c == 's')
		return (ft_putstr(va_arg(valist, char *))); // Print a string
	else if (c == 'p')
	{
		unsigned long int num = (unsigned long int)va_arg(valist, void *);
		if (num == 0)
			return (ft_putstr("(nil)")); // Prints (nil) if pointer is pointing towards NULL
		else
			return (ft_putstr("0x") + ft_tohex(num, 'a')); // Print a pointer in hexadecimal format with '0x' prefix
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(valist, int))); // Print a decimal integer
	else if (c == 'u')
		return (ft_putnbr(va_arg(valist, unsigned int))); // Print an unsigned integer
	else if (c == 'x')
		return (ft_tohex(va_arg(valist, unsigned int), 'a')); // Print an unsigned integer in lowercase hexadecimal
	else if (c == 'X')
		return (ft_tohex(va_arg(valist, unsigned int), 'A')); // Print an unsigned integer in uppercase hexadecimal
	else if (c == '%')
		return (ft_putchar('%')); // Print a percent sign
	else
		return (-1); // Invalid format specifier, do nothing
}

int ft_printf(const char *args, ...)
{
	va_list valist;
	int len = 0;

	va_start(valist, args); // Initialize valist to point to the first optional argument
	while (*args)
	{
		if (*args == '%')							// If '%' is encountered, handle format specifier
			len += ft_print_var(*(++args), valist); // Increment length based on the characters printed by ft_print_var
		else
			len += ft_putchar(*args); // Increment length for each non-format specifier character
		args++;						  // Move to the next character in the format string
	}
	va_end(valist); // Clean up the va_list

	return len; // Return the total number of characters printed
}
