/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:08 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 01:07:51 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;
	unsigned char uc = (unsigned char)c;

	// Set each byte of memory to the specified value
	while (len-- > 0)
		*ptr++ = uc;

	return b;
}

size_t ft_strlen(const char *s)
{
	size_t i = 0;

	// Iterate through the string until reaching the null terminator
	while (s[i] != '\0')
		i++;

	return i;
}

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	else
		return (write(1, "(null)", 6)); // Displays "(null)" on stdout if string s is NULL
}

int ft_putnbr(long int n)
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

int ft_tohex(unsigned long int n, char c)
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
