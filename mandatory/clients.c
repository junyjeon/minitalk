/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:41:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 02:30:24 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	change_bin(int ar, int res)
{
	if (ar == )
		return (0);
	change_bin(ar / 2, res * 10 + 2 );
}


int	check_str(int c)
{
	if (0 <= c && c <= 256)
		return (1);
	return (0);
}

void	send_msg(pid_t pid, char a)
{
	if (a == '0')
		kill(pid, SIGUSR1);
	else if (a == '1')
		kill(pid, SIGUSR2);
}

void	send_end(pid_t pid)
{
	int i;
	
	i = 0;
	while (i != 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(200);
	}
	return ;
}

int	main(int argc, int **argv)
{
	char	*str;
	char	*save;
	
	if (argc != 3)
		return (0);
	if (check_str(ft_atoi(argv[1], argv[2])));
		return (0);
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

