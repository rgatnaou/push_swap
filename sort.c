#include "push_swap.h"
void	swap_ss(t_stack *ab ,int i)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if(!i)
	{
		swap_node(&a);
		write(1, "sa\n", 3);
	}
	else if(i == 1)
	{
		swap_node(&b);
		write(1, "sb\n", 3);	
	}
	else
	{	swap_node(&a);
		swap_node(&b);
		write(1, "ss\n", 3);
	}
	ab->a = a;
	ab->b = b;
}

void	push_pp(t_stack *ab ,int i)
{
	t_nb	*a;
	t_nb	*b;
	a = first_node(ab->a);
	b = first_node(ab->b);
	if(!i)
	{
		if(!ab->size_a)
			return;
		push_node(&a, &b);
		write(1, "pb\n", 3);
		ab->size_a--;
		ab->size_b++;
	}
	else
	{
		if(!ab->size_b)
			return;
		push_node(&b,&a);
		write(1, "pa\n", 3);
		ab->size_a++;
		ab->size_b--;
	}
	ab->a = a;
	ab->b = b;
}

void	rotate_rr(t_stack *ab,int i)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if(i == 0)
	{
		rotate_node(&a);
		write(1, "ra\n", 3);
	}
	else if(i == 1)
	{
		rotate_node(&b);
		write(1, "rb\n", 3);
	}	
	else
	{
		rotate_node(&b);
		rotate_node(&a);
		write(1, "rr\n", 3);
	}
	ab->a =first_node(a);
	ab->b =first_node(b);
}

void	reverse_rotate_rrr(t_stack *ab,int i)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	if(i == 0)
	{
		reverse_rotate_node(&a);
		write(1, "rra\n", 4);
	}
	else if(i == 1)
	{
		reverse_rotate_node(&b);
		write(1, "rrb\n", 4);
	}	
	else
	{
		reverse_rotate_node(&b);
		reverse_rotate_node(&a);
		write(1, "rrr\n", 4);
	}
	ab->a = a;
	ab->b = b;
}

t_stack	*f_stack(t_nb **a,t_nb **b)
{
	t_stack *rtn;

	rtn =malloc(sizeof(t_stack));
	
	if(a)
	{
		rtn->a = first_node(*a);
		rtn->size_a = count_list(rtn->a);
	}
	if(b)
	{
		rtn->b = first_node(*b);
		rtn->size_b = count_list(rtn->b);
	}
	return(rtn);
}