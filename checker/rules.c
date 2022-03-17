/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:18:30 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 15:00:51 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_node(t_nb **head)
{
	t_nb	*node1;
	t_nb	*node2;

	node1 = *head;
	node2 = node1->next;
	node2->prev = NULL;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	*head = node2;	
}

void	push_node(t_nb **node1,t_nb **node2)
{
	t_nb *node_a;
	t_nb *node_b;

	node_a = first_node(*node1);
	if(node_a->next)
	{
		*node1 = node_a->next;
		(*node1)->prev = NULL;
	}
	else
		*node1 = NULL;
	if(*node2)
	{
		node_b = *node2;
		node_a->next = node_b;
		node_b->prev =node_a;	
	}
	else
		node_a->next = NULL;
	*node2 = node_a;
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
	*node = first;
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
	*node = last;
}

