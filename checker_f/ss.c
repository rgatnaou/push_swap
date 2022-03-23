/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:30:47 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/23 17:31:01 by rgatnaou         ###   ########.fr       */
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

void	sa(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	swap_node(&a);
	write(1, "sa\n", 3);
	ab->a = a;
}

void	sb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	swap_node(&b);
	write(1, "sb\n", 3);
	ab->b = b;
}

void	ss(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	swap_node(&a);
	swap_node(&b);
	write(1, "ss\n", 3);
	ab->a = a;
	ab->b = b;
}
