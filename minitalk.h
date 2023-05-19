/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:12:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:41:14 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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

#endif
