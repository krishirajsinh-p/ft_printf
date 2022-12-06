/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/06 21:06:46 by kpuwar           ###   ########.fr       */
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
			len += ft_print_var(*(++args), valist);
		else
			len += ft_putchar(*args);
		args++;
	}
	va_end(valist);
	return (len);
}
