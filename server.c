/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 22:02:37 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_server;

void	reset_state(t_Client *cl, int pid)
{
	write(1, "interupt\n", 9);
	kill(pid, SIGUSR2);
	kill(g_server.pid, SIGUSR2);
	g_server.pid = 0;
	ft_memset(cl, 0, sizeof(cl));
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_Client	cl;

	(void)context;
	if (info->si_pid == 0)
		return ;
	if (g_server.pid == 0)
		g_server.pid = info->si_pid;
	if (g_server.pid != info->si_pid)
	{
		reset_state(&cl, info->si_pid);
		return ;
	}
	if (sig == SIGUSR2)
		cl.tmp |= (1 << (7 - cl.bit));
	if (++cl.bit == 8)
	{
		if (cl.tmp == '\0')
		{
			g_server.pid = 0;
			ft_memset(&cl, 0, sizeof(cl));
			return ;
		}
		write(1, &(cl.tmp), 1);
		ft_memset(&cl, 0, sizeof(cl));
	}
	g_server.flag = 1;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	ft_putstr("sig : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		if (g_server.flag == 1)
		{
			g_server.flag = 0;
			if (kill(g_server.pid, SIGUSR1) == -1)
				write(2, "<KILL ERROR>", 13);
		}
	}
	return (0);
}
