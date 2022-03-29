/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:08:37 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/03/26 15:29:33 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	check_sort(t_nb *head)
{
	t_nb	*tmp;

	if (head == NULL)
		exit(0);
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->prev->nb > tmp->nb)
			return (0);
	}
	free_node(head);
	return (1);
}

void	check_nbr(char **spl, int i, int len)
{
	int	j;

	j = i + 1;
	while (spl[j])
	{
		if (ft_atoi(spl[j]) == ft_atoi(spl[i]))
		{
			write(2, "Error :Repeated Number.\n", 25);
			ft_free(spl, len);
			exit(1);
		}
		j++;
	}
	if (!check_dgit(spl[i]) || ft_atoi(spl[i]) != (int)ft_atoi(spl[i]))
	{
		write(2, "Error :Invalid Number.\n", 24);
		ft_free(spl, len);
		exit(1);
	}
}

t_nb	*fill(char **spl, int len)
{
	int		i;
	int		j;
	int		index;
	t_nb	*node;

	i = 0;
	while (spl[i])
	{
		j = 0;
		index = len - 1;
		while (spl[j])
			if (ft_atoi(spl[i]) < ft_atoi(spl[j++]))
				index--;
		if (i == 0)
			node = add_new(spl[i], index);
		else
			add_back(&node, add_new(spl[i], index));
		i++;
	}
	ft_free(spl, i);
	if (check_sort(node))
		exit(0);
	return (node);
}

t_nb	*check_arg(char **av, int ac)
{
	int		i;
	int		len;
	char	**spl;
	char	*join;

	if (ac < 3)
		exit(0);
	i = 1;
	join = str_dup(av[i], str_len(av[i]));
	while (av[++i])
		join = str_join(join, av[i]);
	spl = ft_split(join, ' ');
	i = -1;
	len = 0;
	while (spl[len])
		len++;
	while (spl[++i])
		check_nbr(spl, i, len);
	return (fill(spl, len));
}
