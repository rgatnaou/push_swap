/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:15:02 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/08 16:44:35 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = malloc(str_len(s1) + str_len(s2) + 2);
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	join[j++] = ' ';
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = 0;
	free(s1);
	return (join);
}

char	*str_dup(char *str, int len)
{
	char	*dup;
	int		i;

	i = -1;
	if (!str)
		return (NULL);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}

int	check_dgit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	sum;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}	
	if (str[i] == '+')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (sum * sign);
}
