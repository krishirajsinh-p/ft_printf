/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2024/03/19 13:07:00 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Outputs a number to the stdout.
 *
 * @param n The number to output.
 * @return returns the number length after printing successfully on the stdout.
 */
static int ft_putnbr(long int n)
{
	char arr[10] = {0};
	short i = 0;
	short len = 0;

	if (n == 0)
		return (ft_putchar('0'));

	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	while (n > 0)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	len += i;
	while (i--)
		ft_putchar(arr[i]);
	return (len);
}

/**
 * @brief Outputs a hexadecimal value (both in uppercase and lowercase) to the stdout.
 *
 * @param n The number to output in hexadecimal.
 * @param c has to be either 'a' for lowercase hex val or 'A' for uppercase.
 * @return returns the hexadecimal's length after printing successfully on the stdout.
 */
static int ft_tohex(unsigned long int n, char c)
{
	char arr[16] = {0};
	short i = 0;
	short temp;

	if (n == 0)
		return (ft_putchar('0'));

	while (n)
	{
		temp = n % 16;
		if (temp > 9)
			arr[i++] = (temp - 10) + c;
		else
			arr[i++] = temp + '0';
		n /= 16;
	}
	temp = i;
	while (i--)
		ft_putchar(arr[i]);
	return (temp);
}

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
