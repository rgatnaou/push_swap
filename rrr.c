/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:06 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/29 14:18:10 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	reverse_rotate_node(&a);
	write(1, "rra\n", 4);
	ab->a = a;
}

void	rrb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	reverse_rotate_node(&b);
	write(1, "rrb\n", 4);
	ab->b = b;
}

void	rrr(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	reverse_rotate_node(&b);
	reverse_rotate_node(&a);
	write(1, "rrr\n", 4);
	ab->a = a;
	ab->b = b;
}
