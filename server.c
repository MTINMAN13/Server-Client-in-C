/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:48:43 by mman              #+#    #+#             */
/*   Updated: 2024/01/14 21:21:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bit_count = 0;

int	ft_convert(volatile char *binaryString)
{
	int	result;

	result = 0;
	while (*binaryString)
	{
		result = (result << 1) + (*binaryString - '0');
		binaryString++;
	}

	return (result);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static volatile char			bit_stash[7];

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		bit_stash[g_bit_count] = '0';
	}
	else if (signal == SIGUSR2)
	{
		bit_stash[g_bit_count] = '1';
	}
	g_bit_count++;
	if (g_bit_count == 8)
	{
		ft_printf("%c",ft_convert(bit_stash));
		ft_bzero((char *)bit_stash, 8);
		g_bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	ft_printf("SERVER || %i || ONLINE\n\n", getpid());
	while (1)
		pause();
	return (0);
}
