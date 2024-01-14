/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:24:18 by mman              #+#    #+#             */
/*   Updated: 2024/01/14 21:21:02 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SO TO IMPLEMENT THE BONUS< I WILL FIRST TRACK THE LENGTH OF THE TRANSMISSION
// AND SEND IT AT THE BEGINNING OF THIS TRANSMISSION
// THEN AFTER THE TRANSMISSION IS RECEIVED IN FULL< I WILL
// SEND BACK THE HANDSHAKE

// Eliminate - PLAY!

#include "minitalk.h"

void	send_signal(int pid, unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1;
		if (bit == 0)
		{
			ft_printf("sending a zero\n");
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_printf("sending a one\n");
			kill(pid, SIGUSR2);
		}
		usleep(100);
		i--;
	}
	ft_printf("\n");
}

void	ft_error(int num, char *thing)
{
	if (num <= 2)
		ft_printf("ERROR | You sent an insufficient number of parameters.\n");
	else if (num >= 4)
		ft_printf("ERROR | Too many parameters!\n");
	if (!(thing[0] > 47 && thing[0] < 58))
		ft_printf("\n\nERROR | Bad format.\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*msg;

	if (argc != 3 || !(argv[1][0] > 47 && argv[1][0] < 58))
	{
		ft_error(argc, argv[1]);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
	{
		send_signal(pid, (unsigned char) msg[i]);
		i++;
	}
	send_signal(pid, '\n');
	ft_printf("CLIENT | Sending %d symbols:\nCLIENT | %s", i, argv[2]);
	return (0);
}
