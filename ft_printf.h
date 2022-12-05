/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:17:06 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/05 06:17:29 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *args, ...);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long int n);
int		ft_tohex(unsigned long int n, char c);
int		ft_print_var(char c, va_list valist);

#endif
