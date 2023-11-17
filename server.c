#include "minitalk.h"

// void	handler(int sigsent)
// {
// 	static unsigned char	buff;
// 	static int				i;

// 	buff |= (sigsent == SIGUSR1);
// 	i++;
// 	if (i == 8)
// 	{
// 		ft_printf("%c", buff);
// 		i = 0;
// 		buff = 0;
// 	}
// 	else
// 		buff <<= 1;
// }

void handler(int signum, siginfo_t *info, void *context)
{
	ucontext_t	*ucontext;

	ucontext = (ucontext_t *)context;
	ft_printf("Received signal %d from process ID %d\n", signum, info->si_pid);
	ft_printf("ucontext_t address: %p\n", (void *)ucontext);
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("SERVER | %i\n(./server &)\n", getpid());
	ft_printf(">SERVER ID IS: %i\n", getpid());

	while (1)
		pause();

	return 0;
}

/*

so i in this case want my server to continously run and correctly print out the signal
when its received with the proper PID attached to it. I do have a separate client program
already made. I also want the server to exit when i send "exit" into it


*/
