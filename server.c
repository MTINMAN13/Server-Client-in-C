#include "libft/includes/libft.h"

void	handler(int sigsent)
{
	static unsigned char	buff;
	static int				i;

	buff |= (sigsent == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int	main(void)
{
	ft_printf(">CLIENT ID IS: %i\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause ();
	return (0);
}
