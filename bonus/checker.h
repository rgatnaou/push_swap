/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:10:03 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/09 18:17:51 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>

typedef struct s_number
{
	int				nb;
	int				index;
	struct s_number	*next;
	struct s_number	*prev;
}t_nb;

typedef struct s_stack
{
	t_nb	*a;
	t_nb	*b;
	int		size_a;
	int		size_b;
}t_stack;

int		str_len(char *str);
char	*str_join(char *s1, char *s2);
char	*str_dup(char *str, int len);
char	**ft_split(char *str, char c);
int		check_sort(t_nb *head);
int		str_char(char *s1, char *s2);
int		check_dgit(char *str);
long	ft_atoi(char *str);
void	ft_free(char **str, int len);
t_nb	*check_arg(char **av, int ac);
char	*get_next_line(void);
void	add_back(t_nb **old, t_nb *node);
t_nb	*add_new(char *s, int index);
void	free_node(t_nb *node);
t_nb	*first_node(t_nb *node);
t_nb	*last_node(t_nb *node);
int		count_list(t_nb *head);
t_stack	*f_stack(t_nb **a, t_nb **b);
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