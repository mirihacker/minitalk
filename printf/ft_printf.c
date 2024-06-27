/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:54:06 by smiranda          #+#    #+#             */
/*   Updated: 2024/05/20 15:54:25 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*s != '\0')
	{
		print_char((int)*s);
		i++;
		s++;
	}
	return (i);
}

int	print_format(char specifier, va_list ap)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += print_char(va_arg(ap, int));
	else if (specifier == 's')
		i += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += print_digit((long)va_arg(ap, int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		i += print_digit((long)va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == 'u')
		i += print_unsigned((long)va_arg(ap, unsigned int));
	else if (specifier == 'p')
		i += print_pointer(va_arg(ap, uintptr_t));
	else if (specifier == '%')
		i += print_char('%');
	else
		i += write(1, &specifier, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i += print_format(*(++format), ap);
		}
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (i);
}
