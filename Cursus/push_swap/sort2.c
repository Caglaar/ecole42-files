

#include "push_swap.h"

int	ft_sort_small_b(t_stack **a, t_stack **b, int len)
{
	if (len == 1)
	{
		pa(a, b, 1);
	}
	else if (len == 2)
	{
		if ((*b)->d < (*b)->n->d)
			sb(b, 1);
		while (len--)
			pa(a, b, 1);
	}
	else if (len == 3)
	{
		while (len || !((*a)->d < (*a)->n->d && (*a)->n->d < (*a)->n->n->d))
		{
			if (len == 1 && (*a)->d > (*a)->n->d)
				sa(a, 1);
			else if (len == 1 || (len >= 2 && (*b)->d > (*b)->n->d)
				|| (len == 3 && (*b)->d > (*b)->n->n->d))
				len = ft_push(a, b, len, 1);
			else
				sb(b, 1);
		}
	}
	return (0);
}

void	ft_quicksort_3a(t_stack **a, t_stack **b, int len)
{
	if (len == 3 && stacksize(*a) == 3)
		ft_sort_three(a);
	else if (len == 2)
	{
		if ((*a)->d > (*a)->n->d)
			sa(a, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || !((*a)->d < (*a)->n->d
				&& (*a)->n->d < (*a)->n->n->d))
		{
			if (len == 3 && (*a)->d > (*a)->n->d && (*a)->n->n->d)
				sa(a, 1);
			else if (len == 3 && !((*a)->n->n->d > (*a)->d
					&& (*a)->n->n->d > (*a)->n->d))
				len = ft_push(a, b, len, 0);
			else if ((*a)->d > (*a)->n->d)
				sa(a, 1);
			else if (len++)
				pa(a, b, 1);
		}
	}
}

int	ft_get_middle(int *pivot, t_stack **stack_a, int size)
{
	int		i;
	int		*tmp;
	t_stack	*a;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	a = *stack_a;
	while (i < size)
	{
		tmp[i] = a->d;
		a = a->n;
		i++;
	}
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

int	ft_quicksort_a(t_stack **a, t_stack **b, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(a, 'a', len) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3a(a, b, len);
		return (1);
	}
	if (!ft_get_middle(&pivot, a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if ((*a)->d < pivot && (len--))
			pb(b, a, 1);
		else if (++count)
			ra(a, 1);
	}
	while (items / 2 + items % 2 != stacksize(*a) && count--)
		rra(a, 1);
	return (ft_quicksort_a(a, b, items / 2 + items % 2, 0) 
		&& ft_quicksort_b(a, b, items / 2, 0));
	return (1);
}

int	ft_quicksort_b(t_stack **a, t_stack **b, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && is_sorted(b, 'b', len) == 1)
		while (len--)
			pa(a, b, 1);
	if (len <= 3)
	{
		ft_sort_small_b(a, b, len);
		return (1);
	}
	items = len;
	if (!ft_get_middle(&pivot, b, len))
		return (0);
	while (len != items / 2)
	{
		if ((*b)->d >= pivot && len--)
			pa(a, b, 1);
		else if (++count)
			rb(b, 1);
	}
	while (items / 2 != stacksize(*b) && count--)
		rrb(b, 1);
	return (ft_quicksort_a(a, b, items / 2 + items % 2, 0)
		&& ft_quicksort_b(a, b, items / 2, 0));
}
