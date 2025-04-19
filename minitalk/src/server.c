/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:58:38 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/19 16:40:15 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg = NULL;

void	init_msg()
{
	g_msg = malloc(1);
	if (!g_msg)
	{
		write(1, "Malloc failed\n", 14);
		exit(1);
	}
	g_msg[0] = '\0';
}

void	print_msg(pid_t c_pid)
{
	ft_putstr_fd(g_msg, 1);
	free (g_msg);
	g_msg = NULL;
	kill(client_pid, SIGUSR2);
}

char	*add_char_to_msg(char c)
{
	int	i;
	int	j;
	char	*new_msg;

	i = ft_strlen(g_msg);
	new_msg = malloc(i + 2);
	if (!new_msg)
	{
		free(g_msg);
		write(1, "Malloc failed\n", 14);
		exit(1);
	}
	j = 0;
	while (j < i)
	{
		new_msg[j] = g_msg[j];
		j++;
	}
	new_msg[i] = c;
	new_msg[i + 1] = '\0';
	free (g_msg);
	return (new_msg);
}

void	handler(int signum, siginfo_t *info,  void *ucontext)
{
	(void)ucontext;
	static int	i = 0;
	static char	byte = 0;
	static pid_t	client_pid = 0;

	if (!g_msg)
		init_msg();
	if (info->si_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR2)
		byte |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (byte == 0)
			print_msg(client_pid);
		else
			g_msg = add_char_to_msg(byte);
		i = 0;
		byte = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("This is the server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
