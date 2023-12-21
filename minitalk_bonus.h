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

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned int n);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	print_error(char *str);
void	*ft_memset(void *s, int c, size_t n);

typedef struct s_Client
{
	int	tmp;
	int	bit;
}	t_Client;

typedef struct s_info
{
	int	pid;
	int	flag;
}	t_info;

#endif
