#ifndef PUSH_SWAP
#define	PUSH_SWAP

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


#endif