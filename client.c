/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:24:18 by mman              #+#    #+#             */
/*   Updated: 2023/11/20 21:24:23 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SO TO IMPLEMENT THE BONUS< I WILL FIRST TRACK THE LENGTH OF THE TRANSMISSION AND SEND IT AT THE BEGINNING OF THIS TRANSMISSION
// THEN AFTER THE TRANSMISSION IS RECEIVED IN FULL< I WILL SEND BACK THE HANDSHAKE

#include "minitalk.h"

// TODO check if County + the new MSG merger work as intended
// TODO check if the msg is combined and syntaxed properly
// TODO check if its then properly parsed and sent

size_t	county(const char *input)
{
	size_t				trans_length;
	unsigned char		octet;
	int					i;

	if (!input)
		return 0;
	trans_length = 0;
	while (*input)
	{
		octet = (unsigned char)(*input);
		i = 7;
		while (i >= 0)
		{
			trans_length += (octet >> i) & 1;
			--i;
		}
		++input;
	}

	return (trans_length);
}

void	send_signal(int pid, unsigned char octet) {
	int				i; // Start from the most significant bit
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1; // Extract the i-th bit
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		// ft_printf("%i", bit);
		// ft_printf("Currently sending %i\n", bit);
		i--; // Move to the next bit
	}
	ft_printf("\n");
}

void	ft_error(int num, char *thing) {
	if (num <= 2)
		ft_printf("ERROR | You sent an insufficient number of parameters.\n");
	else if (num >= 4)
		ft_printf("ERROR | Too many parameters!\n");
	if (!(thing[0] > 47 && thing[0] < 58))
		ft_printf("\n\nERROR | The provided PID parameter is not an integer. Pls... \n");
}

// todo -- receiver of the single signal, which then prints the PROCESS ID of the SENDER

void	receiver()
{

}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_send;
	int		i;
	char	*len;
	char	*msg;

	if (argc != 3 || !(argv[1][0] > 47 && argv[1][0] < 58))
	{
		ft_error(argc, argv[1]);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str_send = argv[2];
	i = 0;
	len = ft_itoa(county(str_send) + 8);
	msg = ft_strjoin(len, (ft_strjoin("|||", str_send)));
	while (msg[i])
	{
		send_signal(pid, (unsigned char) msg[i]);
		i++;
	}
	send_signal(pid, '\n');
	ft_printf("CLIENT | Sending %d symbols:\nCLIENT | %s", i, argv[2]);
	return (0);
}

// after sending the signal, pause up until we receive the signal back.
// if we dont receive it after a brief pause, say no such servers
// need to fix the "i" - which now displays also the prefix and the syntaxing element

// when i send "hi" it says 15|||hi
// this is byte from h, byte from i and a byte from the newline character at the end of transmission
