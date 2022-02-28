#include "push_swap.h"

int	count_list(t_nb *head)
{
	int	count;

	count = 0;
	if(!head)
		return(0);
	first_node(head);
	while(head)
	{
		count++;
		head = head->next;
	}
	return(count);
}

void	swap_node(t_nb **head)
{
	t_nb	*node1;
	t_nb	*node2;

//	if(!(*head) || !((*head)->next))
//	{
//		write(1,"error swap s?.\n",15);
//		return;
//	}
	node1 = *head;
	node2 = node1->next;
	node2->prev = NULL;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	head = &node2;
}

void	push_node(t_nb **node,t_nb **node2)
{
	t_nb *node_a;
	t_nb *node_b;

	if(!(*node))
	{
		write(1,"error push a<->b.\n",18);
		exit(1);
	}
	node_a = first_node(*node);
	if(node_a->next)
	{
		node = &node_a->next;
		node_a->next->prev = NULL;
	}
	node_a->prev = NULL;
	if(node2)
	{
		node_b = *node2;
		node_a->next = node_b;
		node_b->prev =node_a;
	}
	else
		node_a->next = NULL;
	node2 = &node_a;	
}
void	rotate_node(t_nb **node)
{
	t_nb	*last;
	t_nb	*first;

	last = last_node(*node);
	first = first_node(*node);
	last->next = first;
	first->prev = last;
	first->next->prev = NULL;
	first->next = NULL;
	first = first_node(*node);
	node = &first;
}
void	reverse_rotate_node(t_nb **node)
{
	t_nb	*last;
	t_nb	*first;

	last = last_node(*node);
	first = first_node(*node);
	last->next = first;
	first->prev = last;
	last->prev->next = NULL; 
	last->prev = NULL;
	node = &last;
}