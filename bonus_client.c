/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:41:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/17 22:57:18 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	send_sig(int pid, char *str, int byte)
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
			bit_tmp = str[i] >> (7 - bit) & 1;
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
	byte = ft_strlen(send);
	send_sig(pid, send, byte);
	send_sig(pid, "\0", byte);
	free(send);
}

void	confirm(int sig)
{
	if (sig != SIGUSR1)
		print_error("Error: Server received message\n");
	write(1, &"END", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		print_error("Wrong number of Argument\n");
	signal(SIGUSR1, confirm);
	pid = ft_atoi(argv[1]);
	get_str(pid, argv[2]);
	while (1)
		;
	return (0);
}