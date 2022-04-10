/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:30:11 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/08 22:35:25 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_node(t_nb **node)
{
	t_nb	*last;
	t_nb	*first;

	last = last_node(*node);
	first = *node;
	last->next = first;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*node = last;
}

void	rra(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	if (ab->size_a)
		reverse_rotate_node(&a);
	ab->a = a;
}

void	rrb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	if (ab->size_b)
		reverse_rotate_node(&b);
	ab->b = b;
}

void	rrr(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if (ab->size_b)
		reverse_rotate_node(&b);
	if (ab->size_a)
		reverse_rotate_node(&a);
	write(1, "rrr\n", 4);
	ab->a = a;
	ab->b = b;
}
