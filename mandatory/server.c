/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:10:55 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/31 22:58:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int	bit;
	int	pid;
	int	count;
	int	dec;
} t_data;

t_data g_data;

void	set_data(int pid)
{
	
}

void	sig_usr2(int signum)
{
	char	a;
	
	(void)signum;
	g_data.bit[g_data.count] = '1';
	g_data.count++;
	if (g_data.count == 8)
	{
		g_data.dec = change_dec(g_data.bit);
		a = (char)g_data.dec;
		write(1, &a, 1);
		g_data.count = 0;
	}
}

void	sig_usr1(int signum)
{
	char	a;
	
	(void)signum;
	g_data.bit[g_data.count] = '0';
	g_data.count++;
	if (g_data.count == 8)
	{
		g_data.dec = change_dec(g_data.bit);
		a = (char)g_data.dec;
		if (a == '\0')
			write(1, "\n", 1);
		else
			write(1, &a, 1);
		g_data.count = 0;
	}
}

int main()
{
	set_data(getpid());
	if (g_data.pid == 0)
		return (0);
	write(1, "pid : ", 6);
	write(1, g_data.pid, strlen(g_data.pid));
	write(1, "\n", 1);
	free(g_data.pid);
	signal(SIGUSR1, sig_sur1);
	signal(SIGUSR1, sig_sur2);
	while (1)
		pause();
	return (0);
}
