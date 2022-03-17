void	ra(t_stack *ab)
{
	t_nb	*a;

	a = first_node(ab->a);
	rotate_node(&a);
	write(1, "ra\n", 3);
	ab->a = first_node(a);
}

void	rb(t_stack *ab)
{
	t_nb	*b;

	b = first_node(ab->b);
	rotate_node(&b);
	write(1, "rb\n", 3);
	ab->b = first_node(b);
}

void	rr(t_stack *ab)
{
	t_nb	*a;
	t_nb	*b;

	a = first_node(ab->a);
	b = first_node(ab->b);
	rotate_node(&b);
	rotate_node(&a);
	write(1, "rr\n", 3);
	ab->a = first_node(a);
	ab->b = first_node(b);
}