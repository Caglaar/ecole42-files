#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				d;
	struct s_stack	*n;
}	t_stack;

typedef struct s_arg
{
	int	has_arg;
}	t_arg;

void	check_arguments(char **str_list, t_arg *arg);
void	error_case(char *s, int status);
int		is_duplicate(char **list);
int		is_init_list(char **list);
int		is_int_item(char *lst);
void	init_stack_a(t_stack **stack_a, char **list);
void	push_init(t_stack **stack, int nb);
t_stack	*ft_stacknew(int nb);
t_stack	*laststack(t_stack **stack);
int		stacksize(t_stack *a);
int		ft_sort(t_stack **a, t_stack **b, int size);
int		is_sorted(t_stack **stack, char c, int len);
char	**select_add_list(int argc, char **argv, t_arg	*arg);
void	rotate(t_stack **stack);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	swap(t_stack **stack);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);
void	ft_quicksort_3a(t_stack **a, t_stack **b, int len);
int		ft_get_middle(int *pivot, t_stack **stack_a, int size);
int		ft_quicksort_a(t_stack **a, t_stack **b, int len, int count);
int		ft_quicksort_b(t_stack **a, t_stack **b, int len, int count);
void	ft_sort_three(t_stack **a);
int		ft_push(t_stack **a, t_stack **b, int len, int operation);
void	ft_sort_int_tmp(int *tmp_stack, int size);
int		ft_sort_small_b(t_stack **a, t_stack **b, int len);
void	ft_stack_clear(t_stack	**stack);
void	error(t_stack **a, t_stack **b, int flag);

#endif
