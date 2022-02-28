#include "push_swap.h"
void	swap_ss(t_stack *ab ,int i)
{
	ab->a = first_node(ab->a);
	ab->b = first_node(ab->b);
	if(!i)
	{
		swap_node(&(ab->a));
		write(1, "sa\n", 3);
	}
	else if(i == 1)
	{
		swap_node(&(ab->b));
		write(1, "sb\n", 3);	
	}
	else
	{	swap_node(&(ab->b));
		swap_node(&(ab->b));
		write(1, "ss\n", 3);
	}
}

void	push_pp(t_stack *ab ,int i)
{
	if(!i)
	{
		push_node(&(ab->b), &(ab->a));
		write(1, "pa\n", 3);
	}
	else
	{
		push_node(&(ab->a),&(ab->b));
		write(1, "pb\n", 3);
	}
}

void	rotate_rr(t_stack *ab,int i)
{
	if(i == 0)
	{
		rotate_node(&(ab->a));
		write(1, "ra\n", 3);
	}
	if(i == 1)
	{
		rotate_node(&(ab->b));
		write(1, "rb\n", 3);
	}	
	else
	{
		rotate_node(&(ab->b));
		rotate_node(&(ab->a));
		write(1, "rr\n", 3);
	}
}

void	reverse_rotate_rrr(t_stack *ab,int i)
{
	if(i == 0)
	{
		reverse_rotate_node(&(ab->a));
		write(1, "rra\n", 3);
	}
	if(i == 1)
	{
		reverse_rotate_node(&(ab->b));
		write(1, "rrb\n", 3);
	}	
	else
	{
		reverse_rotate_node(&(ab->b));
		reverse_rotate_node(&(ab->a));
		write(1, "rrr\n", 3);
	}
}