#include<stdio.h>
#include "push_swap.h"

int main(int ac,char **av)
{
	t_nb	*node;
	t_nb	*tmp;
	node = check_arg(av,ac);
	tmp = node;
	while(tmp)
	{
		printf("nb:%d ; index:%d ; \n",node->nb,node->index);
		node = node->next;
	}
	printf("\n\n");
	swap_node(&tmp);
	while(tmp)
	{
		printf("nb:%d ; index:%d ; \n",tmp->nb,tmp->index);
		tmp = tmp->next;
	}
}