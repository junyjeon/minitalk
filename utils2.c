/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:30:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:44:55 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(char *str)
{
	while (*str)
		write(1, str++, 1);
	exit(1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
