/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:17:06 by kpuwar            #+#    #+#             */
/*   Updated: 2024/03/19 00:28:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * @brief Outputs an integer to the specified file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor.
 */
int ft_printf(const char *args, ...);

/**
 * @brief Sets the first len bytes of the memory area pointed to by b to the specified value.
 *
 * @param b The pointer to the memory area.
 * @param c The value to be set (interpreted as an unsigned char).
 * @param len The number of bytes to be set.
 * @return A pointer to the memory area b.
 */
void *ft_memset(void *b, int c, size_t len);

/**
 * @brief Calculates the length of the given string.
 *
 * @param s The string to be measured.
 * @return The length of the string.
 */
size_t ft_strlen(const char *s);

/**
 * @brief Outputs a character to the stdout.
 *
 * @param c The character to output.
 * @return returns the char length (1) after printing successfully on the stdout.
 */
int ft_putchar(char c);

/**
 * @brief Outputs a character to the stdout.
 *
 * @param s The string to output.
 * @return returns the string length after printing successfully on the stdout.
 */
int ft_putstr(char *s);

#endif
