
#include "minitalk.h"

void	send_signal(int pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
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
	ft_printf("CLIENT | You have sent %d symbols\n", i);
	return (0);
}
