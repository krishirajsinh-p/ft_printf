/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:08 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/05 05:50:03 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	char	arr[10];
	short	i;
	short	len;

	if (n == 0)
		return (ft_putchar('0'));
	ft_memset(arr, '0', 10);
	len = 0;
	i = 0;
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

int	tohex(unsigned long int n, char c)
{
	char	arr[16];
	short	i;
	short	temp;

	if (n == 0)
		return (ft_putchar('0'));
	ft_memset(arr, '0', 16);
	i = 0;
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

int	print_var(char c, va_list valist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(valist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(valist, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + \
		tohex((unsigned long int) va_arg(valist, unsigned long int), 'a'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(valist, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(valist, unsigned int)));
	else if (c == 'x')
		return (tohex(va_arg(valist, unsigned int), 'a'));
	else if (c == 'X')
		return (tohex(va_arg(valist, unsigned int), 'A'));
	else
		return (ft_putchar('%'));
}
