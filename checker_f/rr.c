/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:29:08 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/29 14:20:43 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_node(t_nb **node)
{
	t_nb	*last;
	t_nb	*first;

	first = *node;
	last = last_node(*node);
	last->next = first;
	first->prev = last;
	first->next->prev = NULL;
	first->next = NULL;
	first = first_node(*node);
	*node = first;
}

void	ra(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	rotate_node(&a);
	ab->a = a;
}

void	rb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	rotate_node(&b);
	ab->b = b;
}

void	rr(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	rotate_node(&b);
	rotate_node(&a);
	ab->a = a;
	ab->b = b;
}
