#include"push_swap.h"

void	check_nbv(char **spl,int i,int len)
{
	if(!check_dgit(spl[i]) && ft_atoi(spl[i]) == (int)ft_atoi(spl[i]))
	{
		write(1,"Invalid Number: ",16);
		write(1,spl[i],str_len(spl[i]));
		write(1,"\n",1);
		ft_free(spl,len);
		exit(0);
	}
}
void	check_nbr(char **spl,int i,int len)
{
	int	j;

	j = i + 1;	
	while(spl[j])
	{
		if(ft_atoi(spl[j]) == ft_atoi(spl[i]))
		{
			write(1,"Repeated Number: ",17);
			write(1,spl[j],str_len(spl[i]));
			write(1,"\n",1);
			ft_free(spl,len);
			exit(1);
		}
		j++;
	}
	check_nbv(spl, i, len);
}
t_nb	*fill(char **spl ,int len)
{
	int	i;
	int	j;
	int	index;
	t_nb	*node;

	i = 0;
	while(spl[i])
	{
		j = 0;
		index = len - 1;
		while (spl[j])
		{
			if(ft_atoi(spl[i]) < ft_atoi(spl[j]))
				index--;
			j++;
		}
		if(i == 0)
			node =add_new(spl[i],index);
		else		
			add_back(&node,add_new(spl[i],index));
		i++;
	}
	ft_free(spl,i);
	return(node);
}
t_nb	*check_arg(char **av,int ac)
{
	int		i;
	int		len;
	char	**spl;
	char	*join;

	if (ac < 3)
	{
		write(1, "Give Me More Arg.\n", 18);
		exit(1);
	}
	i = 1;
	join = str_dup(av[i],str_len(av[i]));
	while(av[++i])
		join = str_join(join,av[i]);
	spl = ft_split(join, ' ');
	i = -1;
	len = 0;
	while(spl[len])
		len++;
	while(spl[++i])
		check_nbr(spl, i, len);
	return (fill(spl,len));
}
