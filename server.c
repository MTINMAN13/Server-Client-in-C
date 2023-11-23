/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:48:43 by mman              #+#    #+#             */
/*   Updated: 2023/11/23 17:50:02 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bit_count = 0;

void	handler(int signal, siginfo_t *info, void *context)
{
	int								decoded;
	static volatile char			g_bit_buffer[7];

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		g_bit_buffer[g_bit_count] = '0';
	else if (signal == SIGUSR2)
		g_bit_buffer[g_bit_count] = '1';
	g_bit_count++;
	if (g_bit_count == 8)
	{
		decoded = ft_atoi_base((char *)g_bit_buffer, "01");
		ft_strlcpy((char *)g_bit_buffer, "00000000", sizeof(g_bit_buffer));
		ft_printf("%c", decoded);
		g_bit_count = 0;
		usleep(1);
	}
	if (g_bit_count == 0)
		kill(info->si_pid, SIGUSR2);
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
