#include "push_swap.h"

t_nb	*last_node(t_nb *node)
{
	if(!node)
		return(NULL);
	while(node->next)
		node=node->next;
	return(node);
}

t_nb	*first_node(t_nb *node)
{
	if(!node)
		return(NULL);
	while(node->prev)
		node=node->prev;
	return(node);
}

void free_node(t_nb *node)
{
	t_nb *tmp;
	
	if(!node)
		return;
	node = first_node(node);
	while(node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

t_nb	*add_new(char *s,int index)
{
	t_nb *new;

	if(!s)
		return(NULL);
	new = malloc(sizeof(t_nb));
	if(!new)
		return(NULL);
	new->nb = ft_atoi(s);
	new->next =	NULL;
	new->prev = NULL;
	new->index = index;
	return(new);
}

void	add_back(t_nb **old,t_nb *node)
{
	t_nb	*last;

	if(!node)
		return;
	if(*old)
	{
		last = last_node(*old);
		last->next = node;
		node->prev = last;
		node->next  = NULL;
	}
	else
		*old = node;
}