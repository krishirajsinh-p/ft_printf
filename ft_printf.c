/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/22 13:51:06 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *args, ...)
{
	va_list	valist;
	int		num;

	num = count_args(args);
	va_start(valist, num);
	while (*args)
	{
		if (*args == '%')
			print_var(*(++args), valist);
		else
			write(1, args, 1);
		args++;
	}
	va_end(valist);
	return (0);
}

int main(void)
{
	ft_printf("%s %d %x %d\n", "hello\nworld\nhow are you\t??", 50, -100, 90);
	return 0;
}
