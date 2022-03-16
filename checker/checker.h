/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:34:22 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/15 14:25:50 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H
#define	CHECKER_H

#include<unistd.h>
#include<stdlib.h>

char *strdup(char *str);
int	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

typedef struct s_number
{
	int	nb;
	int	index;
	struct s_number *next;
	struct s_number *prev;
}t_nb;

typedef struct s_stack 
{
	t_nb	*a;
	t_nb	*b;
	int		size_a;
	int		size_b;
}t_stack;


#endif