/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:46 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

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
		if (tmp == '\0')
			kill(info->si_pid, SIGUSR1);
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
		;
	return (0);
}
