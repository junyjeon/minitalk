/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 09:05:46 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t g_signal;

void	get_sig(int sig)
{
	static char	tmp;
	static int	bit;

	if (sig == SIGUSR1)
	{
		tmp = 0;
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

int main(void)
{
	ft_putstr_fd("sig : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd("\n", 1);
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		pause();
	return (0);
}

str[i] & 1 == 0 { kill(pid, SIGUSR1)}
str[i] & 1 == 1 { kill(pid, SIGUSR2)}


/*
c : 0000 0001
            1 |
	1	
	c =	c | (1 << i); 
*/


char c = 0;
if sig == USR2;
	c = c | 1;


/**server's routine*/


	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);//block
	sigaddset(&act.sa_mask, SIGUSR2);//block
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &act, NULL) == - 1)
		print_error("Error in value. || Error fault.\n");
	if (sigaction(SIGUSR2, &act, NULL) == - 1)
		print_error("Error in value. || Error fault.\n");
	