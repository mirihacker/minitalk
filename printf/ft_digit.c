/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:02 by smiranda          #+#    #+#             */
/*   Updated: 2024/05/20 15:53:29 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base, const char specifier)
{
	int		i;
	char	*symb;

	symb = "0123456789abcdef";
	if (specifier == 'X')
		symb = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, specifier) + 1);
	}
	if (n < base)
		return (print_char(symb[n]));
	else
	{
		i = print_digit(n / base, base, specifier);
		return (i + (print_digit(n % base, base, specifier)));
	}
}

int	print_digit2(uintptr_t n, uintptr_t base, const char specifier)
{
	int		i;
	char	*symb;

	symb = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, specifier) + 1);
	}
	if (n < base)
		return (print_char(symb[n]));
	else
	{
		i = print_digit(n / base, base, specifier);
		return (i + (print_digit(n % base, base, specifier)));
	}
}

int	print_unsigned(long n)
{
	int		i;
	char	*symb;

	symb = "0123456789";
	if (n < 10)
		return (print_char(symb[n]));
	else
	{
		i = print_unsigned(n / 10);
		return (i + (print_unsigned(n % 10)));
	}
}

int	print_pointer(uintptr_t ptr)
{
	int			p;
	uintptr_t	n;

	p = 0;
	p += write(1, "0x", 2);
	n = (uintptr_t)ptr;
	if (n == 0)
		return (p + (write(1, "0", 1)));
	else
		return (p + (print_digit2(n, 16, 'x')));
}

// int	main(void)
// {
// 	int i;

// 	i = ft_printf("%%c");
// 	ft_printf("The chars written are %d\n", i);
// 	i = printf("%%c");
// 	printf("The chars written are %d\n", i);
// }