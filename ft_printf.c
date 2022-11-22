/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/22 15:41:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *args, ...)
{
	va_list	valist;
	int		num;
	int		len;

	len = 0;
	num = count_args(args);
	va_start(valist, num);
	while (*args)
	{
		if (*args == '%')
			len += print_var(*(++args), valist);
		else
		{
			write(1, args, 1);
			len++;
		}
		args++;
	}
	va_end(valist);
	return (len);
}

int main(void)
{
	printf("%d\n", ft_printf("%s %d %s %u%c", "hello world ", 50, "\nhow are you?? ", -100, '\n'));
	printf("%d", printf("%s %d %s %u%c", "hello world ", 50, "\nhow are you?? ", -100, '\n'));
	return 0;
}
