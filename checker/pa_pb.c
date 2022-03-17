/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:48:53 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 13:53:07 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.c"

void	pb(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;
	
	a = first_node(ab->a);
	b = first_node(ab->b);
	if(!ab->size_a)
		return;
	push_node(&a, &b);
	write(1, "pb\n", 3);
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
	if(!ab->size_b)
		return;
	push_node(&b,&a);
	write(1, "pa\n", 3);
	ab->size_a++;
	ab->size_b--;
	ab->a = a;
	ab->b = b;
}
