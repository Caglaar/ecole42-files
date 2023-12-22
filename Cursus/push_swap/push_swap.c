#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**str_list;
	t_stack	*a;
	t_stack	*b;
	t_arg	arg;

	arg.has_arg = 0;
	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		str_list = select_add_list(argc, argv, &arg);
		check_arguments(str_list, &arg);
		init_stack_a(&a, str_list);
		ft_sort(&a, &b, stacksize(a));
		if (arg.has_arg)
			ft_malloc_error(str_list);
	}
	ft_stack_clear(&a);
}
