/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:17:10 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/15 13:33:22 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char *strdup(char *str)
{
	char *rtn;
	int	i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
		i++;
	rtn = malloc(sizeof(char) * i);
	i = 0;
	while(str[i])
	{
		rtn [i] = str[i];
		i++;
	}
	rtn[i] = 0;
	return(rtn);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && c != '\0' )
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	len;
	int	i;
	int	j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	len = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (0);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}
