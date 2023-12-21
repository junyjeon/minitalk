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

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	tmp;
	static int	bit;

	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		tmp |= 1;
	if (bit < 7)
		tmp <<= 1;
	bit++;
	if (bit == 8)
	{
		write(1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
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
