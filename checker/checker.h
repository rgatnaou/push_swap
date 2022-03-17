/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:34:22 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 14:45:35 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H
#define	CHECKER_H

#include<unistd.h>
#include<stdlib.h>

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

char 	*strdup(char *str);
int		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	swap_node(t_nb **head);
void	push_node(t_nb **node1,t_nb **node2);
void	rotate_node(t_nb **node);
void	reverse_rotate_node(t_nb **node);
void	sa(t_stack *ab);
void	sb(t_stack *ab);
void	ss(t_stack *ab);
void	ra(t_stack *ab);
void	rb(t_stack *ab);
void	rr(t_stack *ab);
void	rra(t_stack *ab);
void	rrb(t_stack *ab);
void	rrr(t_stack *ab);
void	pa(t_stack *ab);
void	pb(t_stack *ab);




#endif