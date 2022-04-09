/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:53:27 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/09 14:27:18 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tree_node(t_stack *ab)
{
	if (ab->size_a == 2)
	{	
		if (ab->a->nb > ab->a->next->nb)
			sa(ab);
	}
	else if (ab->size_a == 3)
	{
		if (ab->a->nb > ab->a->next->next->nb
			&& ab->a->nb > ab->a->next->nb)
			ra(ab);
		if (ab->a->next->nb > ab->a->nb
			&& ab->a->next->nb > ab->a->next->next->nb)
			rra(ab);
		if (ab->a->nb > ab->a->next->nb)
			sa(ab);
	}
}

void	five_node(t_stack *ab)
{
	int		i;

	i = 0;
	if (ab->size_a <= 5)
	{
		while (i < 2)
		{
			if (ab->a->next->index == i || ab->a->next->next->index == i)
				ra(ab);
			else if (ab->a->index != i)
				rra(ab);
			if (ab->a->index == i)
			{
				pb(ab);
				i++;
			}
		}
		tree_node(ab);
		pa(ab);
		pa(ab);
	}
}

void	push_in_b(t_stack *ab, int part)
{
	int	trv;
	int	max;
	int	i;
	// t_nb *tmp;

	i = 1;
	trv = 0;
	while (ab->size_a)
	{
		max = part * i;
		if (ab->a->index <= max)
		{
			pb(ab);
			if (ab->b->index < max - (part / 2))
				rb(ab);
			trv++;
		}
		else
			ra(ab);
		if (trv == max)
			i++;
	}
	// tmp =first_node(ab->b);
	// while(tmp)
	// {
	// 	printf("%d  ",tmp->nb);
	// 	tmp =tmp->next;
	// }
	// printf("\n ");
}

int	get_max(t_stack *ab)
{
	t_nb	*tmp;
	int		pos;

	tmp = ab->b;
	pos = 0;
	while (tmp->index != ab->size_b - 1 && ++pos)
		tmp = tmp->next;
	return (pos);
}

void	push_back(t_stack *ab)
{
	int	pos_max;

	while (ab->size_b)
	{
		pos_max = get_max(ab);
		if (pos_max == 0)
			pa(ab);
		else if (pos_max > ab->size_b / 2)
			rrb(ab);
		else
			rb(ab);
	}
}
