/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:54:47 by smiranda          #+#    #+#             */
/*   Updated: 2024/05/20 15:54:56 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *s);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);
int	print_digit(long n, int base, const char specifier);
int	print_unsigned(long n);
int	print_pointer(uintptr_t ptr);
int	print_digit2(uintptr_t n, uintptr_t base, const char specifier);

#endif