

#include "push_swap.h"

void	ft_stack_clear(t_stack	**stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->n;
		free(tmp);
	}
}

void	error_case(char *s, int status)
{
	ft_printf("%s", s);
	exit(status);
}

void	check_arguments(char **str_list, t_arg *arg)
{
	if (!is_init_list(str_list))
	{
		if (arg->has_arg)
			ft_malloc_error(str_list);
		error_case("Error\n", 1);
	}
	else if (!is_duplicate(str_list))
	{
		if (arg->has_arg)
			ft_malloc_error(str_list);
		error_case("Error\n", 1);
	}
}
