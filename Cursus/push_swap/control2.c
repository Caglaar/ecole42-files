
#include "push_swap.h"

void	push_init(t_stack **stack, int nb)
{
	t_stack	*newstack;

	newstack = ft_stacknew(nb);
	if (!newstack)
	{
		error_case("Error", 1);
		ft_stack_clear(stack);
	}
	newstack->n = *stack;
	*stack = newstack;
}

void	init_stack_a(t_stack **stack_a, char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	while (--i >= 0)
		push_init(stack_a, ft_atoi(list[i]));
}

int	is_int_item(char *lst)
{
	int	i;

	i = 0;
	if (lst[i] == '-' || lst[i] == '+')
		i++;
	while (lst[i])
	{
		if (lst[i] >= 48 && lst[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

int	is_init_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (ft_strlen(list[i]) == 0 || is_int_item(list[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (list[i])
	{
		if (ft_atol(list[i]) <= -2147483648 || ft_atol(list[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (!ft_strcmp(list[i], list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
