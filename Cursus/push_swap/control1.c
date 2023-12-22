

#include "push_swap.h"

char	**select_add_list(int argc, char **argv, t_arg *arg)
{
	char	**str_list;

	if (argc == 2)
	{
		arg->has_arg = 1;
		str_list = ft_split(argv[1], ' ');
	}
	else
		str_list = argv + 1;
	return (str_list);
}

int	is_sorted(t_stack **stack, char c, int len)
{
	int		i;
	t_stack	*first;

	first = *stack;
	i = 1;
	if (c == 'a')
	{
		while (i++ < len)
		{
			if (first->d > first->n->d)
				return (0);
			first = first->n;
		}
	}
	first = *stack;
	if (c == 'b')
	{
		while (i++ < len)
		{
			if (first->d < first->n->d)
				return (0);
			first = first->n;
		}
	}
	return (1);
}

int	stacksize(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a->n != NULL)
	{
		a = a->n;
		i++;
	}
	return (i + 1);
}

t_stack	*laststack(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->n != NULL)
		last = last->n;
	return (last);
}

t_stack	*ft_stacknew(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->d = nb;
	new->n = NULL;
	return (new);
}
