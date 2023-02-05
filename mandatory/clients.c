/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:41:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 09:27:10 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t g_pid;
static volatile sig_atomic_t g_signal;

//int	change_bin(int ar, int res)
//{
//	if (ar == )
//		return (0);
//	change_bin(ar / 2, res * 10 + 2 );
//}

//int	check_str(int c)
//{
//	if (0 <= c && c <= 256)
//		return (1);
//	return (0);
//}

//void	send_msg(pid_t pid, char a)
//{
//	if (a == '0')
//		kill(pid, SIGUSR1);
//	else if (a == '1')
//		kill(pid, SIGUSR2);
//}

//void	send_end(pid_t pid)
//{
//	int i;
	
//	i = 0;
//	while (i != 8)
//	{
//		kill(pid, SIGUSR1);
//		i++;
//		usleep(200);
//	}
//	return ;
//}

void ft_handler(int sig, siginfo_t *info, ucontext_t	*uap)
{
	g_pid = info->si_pid;
	g_signal = sig;
}

int	main(int argc, int **argv)//ar[1]: pid, ar[2]
{
	pid_t	pid;

	char	*str;
	char	*save;
	
	if (argc != 3)
	{
		ft_putstr_fd("Argument is Wrong!!\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	check_str(pid, str);
	while (*argv[2]);
	{
		str = change_bin((int)*argv[2]);
		if (str == 0)
			return (0);
		save = str;
		while (*str)
		{
			send_msg(ft_atoi(argv[1]), *str);
			str++;
			usleep(200);
		}
		argv[2]++;
		free(save);
	}
	send_end(ft_atoi(argv[1]));
	exit(0);
	return (0);
}

(a  + bi )^2 = a^2 - b^2 + 2abi
