/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:41:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 22:04:30 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_sig(int pid, char *str, int byte)
{
	int	i;
	int	bit;
	int	bit_tmp;

	i = -1;
	while (++i < byte)
	{
		bit = 0;
		while (bit < 8)
		{
			bit_tmp = (int)(str[i] >> (7 - bit) & 1);
			if (bit_tmp == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			bit++;
		}
	}
}

void	get_str(int pid, char *str)
{
	int		byte;
	char	*send;

	send = ft_strjoin(str, "\n");
	if (send == NULL)
		exit(1);
	byte = (int)ft_strlen(send);
	send_sig(pid, send, byte);
	free(send);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		print_error("Wrong number of Argument\n");
	pid = ft_atoi(argv[1]);
	get_str(pid, argv[2]);
	while (1)
		;
	return (0);
}
