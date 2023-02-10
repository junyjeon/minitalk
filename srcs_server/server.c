/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/10 17:35:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	tmp;
	static int	bit;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		tmp |= 0;
		if (bit < 7)
			tmp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		tmp |= 1;
		if (bit < 7)
			tmp <<= 1;
	}
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
	ft_putstr_fd("sig : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
