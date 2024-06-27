/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:37 by smiranda          #+#    #+#             */
/*   Updated: 2024/05/21 09:26:59 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int		ft_atoi(const char *nptr);
void	ft_sendbits(int pid, char c);

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Example: ./client <PID> <MESSAGE>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_sendbits(pid, argv[2][i]);
		i++;
	}
	ft_sendbits(pid, '\0');
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	r;

	i = 0;
	sign = 1;
	r = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * r);
}

void	ft_sendbits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}
