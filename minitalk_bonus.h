/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:12:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 22:53:07 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_CLIENTS 10

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned int n);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	print_error(char *str);
int		get_utf8_length(char byte);
int		is_utf8_char(const char *buf, int buf_i);

typedef struct s_Client
{
	int		pid;
	int		tmp;
	int		bit;
	char	buf[4];
	int		buf_i;
}	t_Client;

#endif
