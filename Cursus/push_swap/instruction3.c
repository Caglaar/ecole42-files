
#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->n)
		return ;
	first = *stack;
	second = (*stack)->n;
	first->n = second->n;
	second->n = first;
	*stack = second;
}

void	sa(t_stack **a, int print)
{
	if (stacksize(*a) > 1)
	{
		swap(a);
		if (print)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int print)
{
	if (stacksize(*b) > 1)
	{
		swap(b);
		if (print)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_printf("ss\n");
}
