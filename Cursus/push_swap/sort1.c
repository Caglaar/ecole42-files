

#include "push_swap.h"

int	ft_push(t_stack **a, t_stack **b, int len, int operation)
{
	if (operation == 0)
		pb(b, a, 1);
	else
		pa(a, b, 1);
	len--;
	return (len);
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->d > (*a)->n->d && (*a)->d < (*a)->n->n->d 
		&& (*a)->n->d < (*a)->n->n->d)
		sa(a, 1);
	if ((*a)->d > (*a)->n->d && (*a)->d > (*a)->n->n->d 
		&& (*a)->n->d > (*a)->n->n->d)
	{
		sa(a, 1);
		rra(a, 1);
	}
	if ((*a)->d > (*a)->n->d && (*a)->d > (*a)->n->n->d 
		&& (*a)->n->d < (*a)->n->n->d)
		ra(a, 1);
	if ((*a)->d < (*a)->n->d && (*a)->d < (*a)->n->n->d 
		&& (*a)->n->d > (*a)->n->n->d)
	{
		sa(a, 1);
		ra(a, 1);
	}
	if ((*a)->d < (*a)->n->d && (*a)->d > (*a)->n->n->d 
		&& (*a)->n->d > (*a)->n->n->d)
		rra(a, 1);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_checked_sorted(int *stack_a, int size, int flag)
{
	int	i;

	if (flag == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack_a[i - 1] > stack_a[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack_a[i - 1] < stack_a[i])
				return (0);
			i++;
		}
		return (1);
	}
}

int	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(a, 'a', stacksize(*a)) == 0)
	{
		if (size == 2)
			sa(a, 1);
		else if (size == 3)
			ft_sort_three(a);
		else
			ft_quicksort_a(a, b, size, 0);
	}
	return (0);
}
