

#include "push_swap.h"

void	error(t_stack **a, t_stack **b, int flag)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
	if (flag == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	run(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, 0);
	else
		error(a, b, 1);
}

void	check(char *str, t_stack **a, t_stack **b)
{
	while (str)
	{
		run(str, a, b);
		free(str);
		str = get_next_line(0);
	}
}

void	print(t_stack **a, t_stack **b)
{
	if (is_sorted(a, 'a', stacksize(*a)) && stacksize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	char	**str_list;
	t_stack	*a;
	t_stack	*b;
	t_arg	arg;
	char	*str;

	arg.has_arg = 0;
	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		str_list = select_add_list(argc, argv, &arg);
		check_arguments(str_list, &arg);
		init_stack_a(&a, str_list);
		str = get_next_line(0);
		check(str, &a, &b);
		if (arg.has_arg)
			ft_malloc_error(str_list);
	}
	else
		return (0);
	print(&a, &b);
	error(&a, &b, 0);
	return (0);
}
