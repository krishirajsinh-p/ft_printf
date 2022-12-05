/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/05 03:34:39 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *args, ...)
{
	va_list	valist;
	int		len;

	len = 0;
	va_start(valist, args);
	while (*args)
	{
		if (*args == '%')
			len += print_var(*(++args), valist);
		else
			len += ft_putchar(*args);
		args++;
	}
	va_end(valist);
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	char *name = "500";
	printf("%d\n", ft_printf("%s %p %d %i %u %x %X %% %c",\
	 "this is string", name, 420, 420, -1, 15, 15, '\n'));
	printf("%d\n", printf("%s %p %d %i %u %x %X %% %c",\
	 "this is string", name, 420, 420, -1, 15, 15, '\n'));
	return 0;
}
*/
