/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:03:02 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/29 14:20:01 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_list(t_nb *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	first_node(head);
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_stack	*f_stack(t_nb **a, t_nb **b)
{
	t_stack	*rtn;

	rtn = malloc(sizeof(t_stack));
	if (!rtn)
		return (NULL);
	if (a)
	{
		rtn->a = first_node(*a);
		rtn->size_a = count_list(rtn->a);
	}
	if (b)
	{
		rtn->b = first_node(*b);
		rtn->size_b = count_list(rtn->b);
	}
	return (rtn);
}

void	final_sort(t_stack *ab)
{
	int		part_size;

	if (ab->size_a < 6)
	{
		if (ab->size_a < 4)
			tree_node(ab);
		else
			five_node(ab);
	}
	else
	{
		part_size = ab->size_a / 10 + 12;
		push_in_b(ab, part_size);
		push_back(ab);
	}
}

int	main(int ac, char **av)
{
	t_nb	*a;
	t_nb	*b;
	t_stack	*ab;

	a = check_arg(av, ac);
	ab = f_stack(&a, &b);
	final_sort(ab);
	a = ab->a;
}
