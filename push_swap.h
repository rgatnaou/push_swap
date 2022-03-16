#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

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

int		str_len(char *str);
char	*str_join(char *s1, char *s2);
char	*str_dup(char *str, int len);
char	**ft_split(char *str,char c);
int		check_dgit(char *str);
long	ft_atoi(char *str);
void	ft_free(char **str,int len);
t_nb	*check_arg(char **av, int ac);
void	add_back(t_nb **old,t_nb *node);
t_nb	*add_new(char *s,int index);
void	free_node(t_nb *node);
t_nb	*first_node(t_nb *node);
t_nb	*last_node(t_nb *node);
void	swap_node(t_nb **head);
void	push_node(t_nb **node,t_nb **node2);
void	rotate_node(t_nb **node);
void	reverse_rotate_node(t_nb **node);
int		count_list(t_nb *head);
void	reverse_rotate_rrr(t_stack *ab,int i);
void	rotate_rr(t_stack *ab,int i);
void	push_pp(t_stack *ab ,int i);
void	swap_ss(t_stack *ab ,int i);
t_stack	*f_stack(t_nb **a,t_nb **b);
void	tree_node(t_stack *stack);
void	five_node(t_stack *head);
void 	final_sort(t_stack *ab);
void	big_sort_pr1(t_stack *head, int part_size);
void	check_sort(t_nb *head);
int		main(int ac,char **av);

#endif