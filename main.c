
#include "push_swap.h"

int main(int ac,char **av)
{
	t_nb	*node;
	t_nb	*tmp;
	t_stack	*ab;

	node = check_arg(av,ac);
	check_sort(node);
	ab = f_stack(&node,&tmp);
	final_sort(ab);
	//five_node(ab);
	node = ab->a;
	printf("**%d***\n",ab->size_a);
	while(node->next)
	{
		printf("stack a:nb:%d ; index:%d ; \n",node->nb,node->index);
			node = node->next;
	}
	printf("stack a:nb:%d ; index:%d ; \n",node->nb,node->index);
	node = ab->b;
}