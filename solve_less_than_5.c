/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_less_than_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:43 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:43 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_2(t_list **stack_a)
{
	do_sa(stack_a, True);
}

void	solve_3(t_list **stack_a)
{
	while (check_sorted(*stack_a) != True)
	{
		if ((intptr_t)(*stack_a)->content > (intptr_t)(*stack_a)->next->content)
			do_sa(stack_a, True);
		if (check_sorted(*stack_a) != True)
			do_rra(stack_a, True);
	}
}

void	solve_4(t_list **stack_a, t_list **stack_b)
{
	long int	max;

	max = find_big(stack_a);
	while ((intptr_t)(*stack_a)->content != max)
		do_ra(stack_a, True);
	do_pb(stack_a, stack_b, True);
	solve_3(stack_a);
	do_pa(stack_a, stack_b, True);
	do_ra(stack_a, True);
}

void	solve_5(t_list **stack_a, t_list **stack_b)
{
	long int	median;

	median = find_median((*stack_a));
	while (ft_lstsize((*stack_a)) != 3)
	{
		if ((intptr_t)(*stack_a)->content < median)
			do_pb(stack_a, stack_b, True);
		if ((intptr_t)(*stack_a)->content >= median)
			do_ra(stack_a, True);
	}
	solve_3(stack_a);
	if ((intptr_t)(*stack_b)->content < (intptr_t)(*stack_b)->next->content)
		do_sb(stack_b, True);
	do_pa(stack_a, stack_b, True);
	do_pa(stack_a, stack_b, True);
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
