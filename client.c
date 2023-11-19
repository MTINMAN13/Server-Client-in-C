
#include "minitalk.h"
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
		ft_printf("%i", bit);
		// ft_printf("Currently sending %i\n", bit);
		i--; // Move to the next bit
	}
	ft_printf("\n");
}

void	ft_error(int num)
{
	if (num <= 2)
		ft_printf("ERROR | You sent Insufficient number of parameters.\n");
	if (num >= 4)
		ft_printf("ERROR | Too many parameters!\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_send;
	int		i;

	if (argc != 3)
	{
		ft_error(argc);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str_send = argv[2];
	i = 0;
	while (str_send[i])
	{
		send_signal(pid, (unsigned char)str_send[i]);
		i++;
	}
	send_signal(pid, '\n');
	ft_printf("CLIENT | Sending %d symbols:\nCLIENT | %s", i, argv[2]);
	return (0);
}
