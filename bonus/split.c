/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:31:42 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/28 17:37:46 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	str_char(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (str_len(s1) != str_len(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char **str, int len)
{
	int	i;

	i = 0;
	while (i <= len)
		free(str[i++]);
	free(str);
}

int	word(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

void	write_spl(char *str, char c, int w, char **spl)
{
	int		i;
	int		count;

	count = 0;
	while (count < w)
	{
		while (*str == c)
			str++;
		i = 0;
		while (str[i] != c && str[i] != 0)
			i++;
		spl[count] = str_dup(str, i);
		if (!spl[count])
			ft_free(spl, count);
		str = str + i;
		count++;
	}
}

char	**ft_split(char *str, char c)
{
	int		w;
	char	**spl;

	if (!str)
		return (NULL);
	w = word(str, c);
	spl = (char **)malloc(sizeof(char *) * (w + 1));
	if (!spl)
		return (NULL);
	write_spl(str, c, w, spl);
	spl[w] = 0;
	free(str);
	return (spl);
}
