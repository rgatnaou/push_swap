/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:24:51 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 16:12:38 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	swap_node(&a);
	write(1, "sa\n", 3);
	ab->a = first_node(a);
}

void	sb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	swap_node(&b);
	write(1, "sb\n", 3);
	ab->b= first_node(b);
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
	ab->a = first_node(a);
	ab->b = first_node(b);
}