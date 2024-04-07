/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 01:13:54 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Helper function to select the util function based on character and print the variable in the valist.
 *
 * @param c The character to replace with the value.
 * @param valist The list of all the variables passed during function the call.
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
		return (0); // Invalid format specifier, do nothing
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
