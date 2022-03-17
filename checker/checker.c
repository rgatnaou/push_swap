/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:45:24 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/17 14:58:35 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void	check_rules(char *get_line , t_stack *ab)
{
	if(strcmp(get_line,"sa\n"))
		sa(ab);
	else if(strcmp(get_line,"sb\n"))
		sb(ab);
	else if(strcmp(get_line,"ss\n"))
		ss(ab);
	else if(strcmp(get_line,"ra\n"))
		ra(ab);
	else if(strcmp(get_line,"rb\n"))
		rb(ab);
	else if(strcmp(get_line,"rr\n"))
		rr(ab);
	else if(strcmp(get_line,"rra\n"))
		rra(ab);
	else if(strcmp(get_line,"rrb\n"))
		rrb(ab);
	else if(strcmp(get_line,"rrr\n"))
		rrr(ab);
	else if(strcmp(get_line,"pa\n"))
		pa(ab);
	else if(strcmp(get_line,"pb\n"))
		pb(ab)
	else
	{
		write(2, "ko\n",3);
		exit(1);
	}
}
int main(int ac, char **av)
{
	if(ac < 2)
	{}
	else if()
	
}