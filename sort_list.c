#include "push_swap.h"

void	tree_node(t_stack *head)
{
	if (head->size_a == 2)
	{
		if(head->a->nb > head->a->next->nb)
		{
			//swap_ss(head,0);
			sa(head);
		}
	}
	else if(head->size_a == 3)
	{
		int i = 0;
		while(i < 2)
		{
			if(head->a->nb > head->a->next->next->nb && head->a->nb > head->a->next->nb)
				rra(head);
			if(head->a->next->nb < head->a->nb && head->a->next->nb < head->a->next->next->nb)
				sa(head);
			if(head->a->next->next->nb < head->a->nb || head->a->next->next->nb < head->a->next->nb)
				rra(head);
			i++;
		}
	}
}
void	five_node(t_stack *head)
{
	int		i;

	i = 0;
 	if(head->size_a <= 5)
 	{
		while(i < 2)
		{
			if(head->a->next->index == i)
				ra(head);
			if(head->a->index != i)
				rra(head);
			if(head->a->index == i && i <2)
			{
				pb(head);
				i++;
			}
		}
		tree_node(head);
		pa(head);
		pa(head);
 	}
}

void big_sort_pr1(t_stack *head, int part_size)
{
	int	part_trv;
	int	part_max;
	int	part_no;

	part_no = 1;
	part_trv = 0;
	while(head->size_a)
	{
		part_max = part_size * part_no;
		if(head->a->index < part_max)
		{
			pb(head);
			if (head->b->index < part_max - (part_size / 2))
				rb(head);
			part_trv++;
		}
		else
			rb(head);
		if (part_trv == part_max)
			part_no++;
	}
}

int	get_max(t_stack *obj)
{
	t_nb	*tmp;
	int		pos;

	tmp = obj->b;
	pos = 0;
	while (tmp->index != obj->size_b - 1 && ++pos)
		tmp = tmp->next;
	return (pos);
}

void	push_back(t_stack *obj)
{
	int	pos_max;

	while (obj->size_b)
	{
		pos_max = get_max(obj);
		if (pos_max == 0)
			pa(obj);
		else if (pos_max > obj->size_b / 2)
			rrb(obj);
		else
			rb(obj);
	}
}

void final_sort(t_stack *ab)
{
	int		part_size;

	
	if(ab->size_a < 6)
	{
		if(ab->size_a < 4)
			tree_node(ab);
		else
			five_node(ab);
	}
	else
	{
		part_size = ab->size_a / 10 + 12;
		big_sort_pr1(ab, part_size);
		push_back(ab);
	}
}