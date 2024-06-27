/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:46:47 by smiranda          #+#    #+#             */
/*   Updated: 2024/05/21 09:26:40 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char		*fill_message(char c, char *message);
char		*ft_strdup(const char *s);
int			ft_strlen(const char *str);

static void	handler(int signum)
{
	static int	bit_count = 0;
	static char	current_char = 0;
	static char	*message = NULL;

	if (!message)
		message = ft_strdup("");
	current_char |= (signum == SIGUSR2) << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		message = fill_message(current_char, message);
		if (current_char == '\0')
		{
			printf("%s\n", message);
			free(message);
			message = ft_strdup("");
		}
		current_char = 0;
		bit_count = 0;
	}
}

char	*fill_message(char c, char *message)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ((ft_strlen(message)) + 2));
	if (!str)
		return (NULL);
	while (message[i])
		str[j++] = message[i++];
	str[j++] = c;
	str[j] = '\0';
	free(message);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Ready for message\n");
	signal_received.sa_handler = handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
	return (0);
}
