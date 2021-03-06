/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:28:41 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/08 18:27:14 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_list(t_nb *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	first_node(head);
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_stack	*f_stack(t_nb **a, t_nb **b)
{
	t_stack	*rtn;

	rtn = malloc(sizeof(t_stack));
	if (!rtn)
		return (NULL);
	if (a)
	{
		rtn->a = first_node(*a);
		rtn->size_a = count_list(rtn->a);
	}
	if (b)
	{
		rtn->b = first_node(*b);
		rtn->size_b = count_list(rtn->b);
	}
	return (rtn);
}

void	push_node(t_nb **node1, t_nb **node2)
{
	t_nb	*node_a;
	t_nb	*node_b;

	node_a = *node1;
	if (node_a->next)
	{
		*node1 = node_a->next;
		(*node1)->prev = NULL;
	}
	else
		*node1 = NULL;
	if (*node2)
	{
		node_b = *node2;
		node_a->next = node_b;
		node_b->prev = node_a;
	}
	else
		node_a->next = NULL;
	*node2 = node_a;
}

void	pb(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if (!ab->size_a)
		return ;
	push_node(&a, &b);
	ab->size_a--;
	ab->size_b++;
	ab->a = a;
	ab->b = b;
}

void	pa(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if (!ab->size_b)
		return ;
	push_node(&b, &a);
	ab->size_a++;
	ab->size_b--;
	ab->a = a;
	ab->b = b;
}
