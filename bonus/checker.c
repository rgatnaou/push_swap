/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:26:44 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/09 20:14:27 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rules_c2(char	*line, t_stack	*ab)
{
	if (str_char(line, "rra\n"))
		rra(ab);
	else if (str_char(line, "rrb\n"))
		rrb(ab);
	else if (str_char(line, "rrr\n"))
		rrr(ab);
	else
	{
		write(2, "error\n", 6);
		free(line);
		free_node(ab->a);
		free_node(ab->b);
		free(ab);
		exit(1);
	}
}

void	rules_c1(char	*line, t_stack	*ab)
{
	if (str_char(line, "sa\n"))
		sa(ab);
	else if (str_char(line, "sb\n"))
		sb(ab);
	else if (str_char(line, "ss\n"))
		ss(ab);
	else if (str_char(line, "pa\n"))
		pa(ab);
	else if (str_char(line, "pb\n"))
		pb(ab);
	else if (str_char(line, "ra\n"))
		ra(ab);
	else if (str_char(line, "rb\n"))
		rb(ab);
	else if (str_char(line, "rr\n"))
		rr(ab);
	else
		rules_c2(line, ab);
}

int	main(int ac, char **av)
{
	t_nb	*a;
	t_nb	*b;
	t_stack	*ab;
	char	*line;

	a = check_arg(av, ac);
	ab = f_stack(&a, &b);
	line = get_next_line();
	while (line)
	{
		rules_c1(line, ab);
		free(line);
		line = get_next_line();
	}
	free(line);
	if (check_sort(ab->a) && ab->size_a && !ab->size_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_node(ab->a);
	free_node(ab->b);
	free(ab);
}
