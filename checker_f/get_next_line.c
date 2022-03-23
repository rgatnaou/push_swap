/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:20:47 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/23 17:47:30 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	size_t	len;
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	len = 0;
	len = str_len(s1);
	len += str_len(s2);
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

char	*get_next_line(int fd)
{
	int			r_rd;
	char		*rd;
	char		*res;

	rd = malloc(2);
	res = malloc(1);
	if (!rd || !res)
		exit(1);
	res[0] = 0;
	r_rd = 1;
	while (!ft_strchr(res, '\n') && r_rd)
	{
		r_rd = read(fd, rd, 1);
		if (r_rd == -1)
		{
			free(rd);
			return (NULL);
		}
		rd[r_rd] = '\0';
		res = ft_strjoin(res, rd);
	}
	free(rd);
	if (!res[0])
		return (NULL);
	return (res);
}
