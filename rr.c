/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:28 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 16:06:58 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	rotate_node(&a);
	write(1, "ra\n", 3);
	ab->a = a;
}

void	rb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	rotate_node(&b);
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
	ab->a = a;
	ab->b = b;
}