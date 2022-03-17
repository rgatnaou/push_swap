/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:26:27 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 14:59:14 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	reverse_rotate_node(&a);
	write(1, "rra\n", 4);
	ab->a = a;
}

void	rra(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	reverse_rotate_node(&b);
	write(1, "rra\n", 4);
	ab->b = b;
}

void	reverse_rotate_rrr(t_stack *ab)
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