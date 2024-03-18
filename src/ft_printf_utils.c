/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:08 by kpuwar            #+#    #+#             */
/*   Updated: 2024/03/18 23:58:34 by kpuwar           ###   ########.fr       */
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
