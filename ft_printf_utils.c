/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:08 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/05 03:31:29 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(long int n)
{
	char	arr[10];
	short	itr;
	short	len;

	if (n == 0)
		return (write(1, "0", 1));
	len = 0;
	itr = 0;
	ft_memset(arr, '0', 10);
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		arr[itr++] = (char)((n % 10) + '0');
		n /= 10;
	}
	while (itr--)
		len += write(1, &arr[itr], 1);
	return (len);
}

int	tohex(long long int n, char c)
{
	char	arr[20];
	short	i;
	short	temp;

	ft_memset(arr, '0', 20);
	i = 0;
	while (n)
	{
		temp = n % 16;
		if (temp > 9)
			arr[i++] = ((temp - 10) + c);
		else
			arr[i++] = (temp + '0');
		n /= 16;
	}
	temp = 0;
	while (i--)
		temp += write(1, &arr[i], 1);
	return (temp);
}

int	print_var(char c, va_list valist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(valist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(valist, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2) + \
		tohex((long long int) va_arg(valist, void *), 'a'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(valist, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(valist, unsigned int)));
	else if (c == 'x')
		return (tohex(va_arg(valist, int), 'a'));
	else if (c == 'X')
		return (tohex(va_arg(valist, int), 'A'));
	else
		return (ft_putchar('%'));
}
