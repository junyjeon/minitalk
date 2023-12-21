/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:57:15 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:39:22 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str >= 7 && *str <= 14)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (0);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

int	get_utf8_length(char byte)
{
	if ((byte & 0x80) == 0)
		return (1);
	else if ((byte & 0xE0) == 0xC0)
		return (2);
	else if ((byte & 0xF0) == 0xE0)
		return (3);
	else if ((byte & 0xF8) == 0xF0)
		return (4);
	return (-1);
}

int	is_utf8_char(const char *buf, int buf_i)
{
	int	length;

	length = get_utf8_length(buf[0]);
	if (length == -1)
		return (0);
	return (buf_i >= length);
}
