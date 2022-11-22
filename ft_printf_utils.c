/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:08 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/22 13:48:13 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_args(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
			count++;
		str++;
	}
	return (count);
}

int	print_var(char c, va_list valist)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(valist, char), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(valist, char *), 1));
	else if (c == 'p')	//pending
		return (ft_putstr_fd(va_arg(valist, char *), 1));
	else if (c == 'd' || c == 'i') //length pending
		return (ft_putnbr_fd(va_arg(valist, int), 1));
	else if (c == 'u') //full pending
		return (ft_putnbr_fd((unsigned int) va_arg(valist, int), 1));
	else if (c == 'x')	//num to hex pending
		return (ft_putnbr_fd(va_arg(valist, int), 1));
	else if (c == 'X')	//cap hex pending
		return (ft_putnbr_fd(va_arg(valist, int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
}

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

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len = ft_strlen(s);
	write(fd, s, sizeof(char) * len);
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	arr[10];
	long	ln;

	ln = n;
	n = 0;
	if (ln == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	ft_memset(arr, '0', 10);
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	while (ln > 0)
	{
		arr[n++] = (char)((ln % 10) + '0');
		ln /= 10;
	}
	while (n--)
		write(fd, &arr[n], 1);
	return (0);
}
