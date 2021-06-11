#include "push_swap.h"

void	solve_2(t_list **stack_a)
{
	do_sa(stack_a);
}

void	solve_3(t_list **stack_a)
{
	while (check_sorted(*stack_a) != True)
	{
		if ((intptr_t)(*stack_a)->content > (intptr_t)(*stack_a)->next->content)
			do_sa(stack_a);
		if (check_sorted(*stack_a) != True)
			do_rra(stack_a);
	}
}

void	solve_4(t_list **stack_a, t_list **stack_b)
{
	long int	min;

	min = find_min(stack_a);
	while ((intptr_t)(*stack_a)->content != min)
		do_ra(stack_a);
	do_pb(stack_a, stack_b);
	solve_3(stack_a);
	do_pa(stack_a, stack_b);
	do_rra(stack_a);
}

void	solve_5(t_list **stack_a, t_list **stack_b)
{
	long int	max;

	while (ft_lstsize((*stack_a)) != 3)
	{
		max = find_big(stack_a);
		//printf("max = %li\n", max);
		while ((intptr_t)(*stack_a)->content != max)
			do_ra(stack_a);
		if ((intptr_t)(*stack_a)->content == max)
			do_pb(stack_a, stack_b);
		//printf("size : %li\n", ft_lstsize((*stack_a)));
	}
	solve_3(stack_a);
	if ((intptr_t)(*stack_b)->content > (intptr_t)(*stack_b)->next->content)
		solve_2(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	return ;
}

void	solve_5_or_less(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		solve_2(stack_a);
	else if (size == 3)
		solve_3(stack_a);
	else if (size == 4)
		solve_4(stack_a, stack_b);
	else if (size == 5)
		solve_5(stack_a, stack_b);
}
