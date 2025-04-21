#include "talk.h"

volatile sig_atomic_t g_kingkai = BUSY;

void	end_handler(int signo)
{
	write(STDOUT_FILENO, "OK!\n", 4);
	exit(EXIT_SUCCESS);
}

void	ack_handler(int signo)
{
	g_kingkai = READY;
}

void	send_char(char c, pid_t kingkai)
{
	int	bit;

	bit = 0;

	while (bit < CHAR_BIT)
	{
		if (c & (0b10000000 >> bit))
			Kill(kingkai, SIGUSR1);
		else
			Kill(kingkai, SIGUSR2);
		++bit;

		while (BUSY == g_kingkai)
			usleep(42);

	}
}

int	main(int ac, char **av)
{
	pid_t	kingkai;
	char	*message;

	if (3 != ac)
	{
		fputs("Usage = ./goku <PID> \"Message\"", stderr);
		exit(EXIT_FAILURE);
	}

	kingkai = atoi(av[1]);
	message = av[2];

	Signal(SIGUSR1, ack_handler, false);
	Signal(SIGUSR2, end_handler, false);

	while (*message)
		send_char(*message++, kingkai);
	send_char('\0', kingkai);

	return EXIT_SUCCESS;
}
