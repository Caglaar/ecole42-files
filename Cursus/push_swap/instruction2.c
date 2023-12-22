
#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!(*stack) || !(*stack)->n)
		return ;
	second_last = *stack;
	last = *stack;
	while (last->n != NULL)
	{
		second_last = last;
		last = last->n;
	}
	last->n = *stack;
	*stack = last;
	second_last->n = NULL;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
