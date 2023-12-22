
#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->n)
		return ;
	first = *stack;
	last = *stack;
	while (last->n != NULL)
		last = last->n;
	*stack = (*stack)->n;
	last->n = first;
	first->n = NULL;
}

void	ra(t_stack **a, int print)
{
	if (stacksize(*a) > 1)
	{
		rotate(a);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int print)
{
	if (stacksize(*b) > 1)
	{
		rotate(b);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
