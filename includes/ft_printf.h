/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:17:06 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 12:52:03 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * @brief Prints formatted data to the standard output according to the format string.
 *
 * This function formats and prints data to the standard output according to the
 * format string `args` and additional arguments. The format string may contain
 * placeholders which are replaced by the values specified in subsequent arguments.
 * The format specifiers follow the same syntax as those used in the standard `printf` function.
 *
 * @param args The format string specifying how subsequent arguments are formatted and printed.
 * @param ... Additional arguments to be formatted and printed according to the format string.
 *
 * @return Upon successful completion, the function returns the number of characters printed
 * (excluding the null byte used to end output to strings). If an output error is encountered,
 * a negative value is returned. In case of an error, the global variable `errno` is set to
 * indicate the cause of the error.
 *
 * @note This function is a custom implementation of the standard `printf` function.
 * It supports a subset of format specifiers and options available in the standard `printf`.
 * Refer to the documentation of the standard `printf` function for more information.
 *
 * @warning This function does not support all features of the standard `printf` function.
 * It is recommended to review the supported format specifiers and options before use.
 * Unsupported or incorrectly used specifiers may result in undefined behavior or errors.
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

/**
 * @brief Outputs a number to the stdout.
 *
 * @param n The number to output.
 * @return returns the number length after printing successfully on the stdout.
 */
int ft_putnbr(long int n);

/**
 * @brief Outputs a hexadecimal value (both in uppercase and lowercase) to the stdout.
 *
 * @param n The number to output in hexadecimal.
 * @param c has to be either 'a' for lowercase hex val or 'A' for uppercase.
 * @return returns the hexadecimal's length after printing successfully on the stdout.
 */
int ft_tohex(unsigned long int n, char c);

#endif
