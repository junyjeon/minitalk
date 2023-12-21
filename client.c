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

int	g_flag;

static void	send_sig(int pid, char *str, int byte)
{
	t_Client	cl;
	int			i;

	i = -1;
	while (++i < byte)
	{
		cl.bit = 0;
		while (cl.bit < 8)
		{
			if (g_flag == 0)
			{
				g_flag = 1;
				cl.tmp = (int)(str[i] >> (7 - cl.bit) & 1);
				if (cl.tmp == 0)
				{
					if (kill(pid, SIGUSR1) == -1)
						print_error("Wrong pid");
				}
				else
					if (kill(pid, SIGUSR2) == -1)
						print_error("Wrong pid");
				++cl.bit;
			}
			usleep(1);
		}
	}
}

static void	post_str(int pid, char *str)
{
	int		byte;
	char	*send;

	send = ft_strjoin(str, "\n");
	if (send == NULL)
		exit(1);
	byte = (int)ft_strlen(send);
	send_sig(pid, send, byte);
	send_sig(pid, "\0", 1);
	free(send);
}

static void	confirm(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 0;
	else if (sig == SIGUSR2)
		print_error("Error Occurred\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		print_error("Wrong number of Argument\n");
	signal(SIGUSR1, confirm);
	signal(SIGUSR2, confirm);
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || 100000 <= pid)
		print_error("PID ERROR");
	post_str(pid, argv[2]);
	write(1, &"Message transfer successful!\n", 29);
	return (0);
}
