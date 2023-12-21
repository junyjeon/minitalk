/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 22:55:10 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "stdio.h"

void	process_multibyte(char *buf, int *buf_i, char byte)
{
	printf("byte: %d buf_index: %d\n", byte, *buf_i);
	buf[*buf_i] = byte;
	(*buf_i)++;
	if (is_utf8_char(buf, *buf_i))
	{
		write(1, buf, *buf_i);
		*buf_i = 0;
	}
}

t_Client	*create_cl(t_Client clients[], int cl_pid)
{
	int	i;

	i = -1;
	while (++i < MAX_CLIENTS)
	{
		if (clients[i].pid == cl_pid || clients[i].pid == 0)
		{
			if (clients[i].pid == 0)
				clients[i].pid = cl_pid;
			return (&clients[i]);
		}
	}
	return (NULL);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_Client	clients[MAX_CLIENTS] = {0};
	t_Client		*cl;
	int				cl_pid;

	cl_pid = info->si_pid;
	cl = create_cl(clients, MAX_CLIENTS, cl_pid);
	(void)context;
	if (sig == SIGUSR2)
		cl->tmp |= 1;
	if (cl->bit < 7)
		cl->tmp <<= 1;
	cl->bit++;
	if (cl->bit == 8)
	{
		if (cl->tmp == '\0')
			kill(info->si_pid, SIGUSR1);
		process_multibyte(cl->buf, &(cl->buf_i), cl->tmp);
		cl->bit = 0;
		cl->tmp = 0;
	}
	// 시그널 보내주기.
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
		usleep(100);
	return (0);
}
