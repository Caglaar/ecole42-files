
#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*first_b;
	t_stack	*second_b;

	if (!*b)
		return ;
	first_b = *b;
	second_b = (*b)->n;
	*b = second_b;
	first_b->n = *a;
	*a = first_b;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, int print)
{
	t_stack	*first_a;
	t_stack	*second_a;

	if (!*a)
		return ;
	first_a = *a;
	second_a = (*a)->n;
	*a = second_a;
	first_a->n = *b;
	*b = first_a;
	if (print)
		ft_printf("pb\n");
}
