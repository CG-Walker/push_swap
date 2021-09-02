/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_half_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:44:43 by walker            #+#    #+#             */
/*   Updated: 2021/09/02 20:45:37 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	a_to_b_ope(t_list **stack_a, t_list **stack_b,
	t_list **chunk, long int median)
{
	if ((intptr_t)(*stack_a)->content < median)
	{
		ft_lstadd_back(&(*chunk), ft_lstnew((*stack_a)->content));
		do_pb(stack_a, stack_b, True);
		return (1);
	}
	else if ((intptr_t)ft_lstlast((*stack_a))->content < median)
		do_rra(stack_a, True);
	else
		do_ra(stack_a, True);
	return (0);
}

void	b_to_a_ope(t_list **s_a, t_list **stack_b,
	t_list **chunks, long int median)
{
	size_t	size_to_push;
	size_t	push;
	int		count_rb;

	push = 0;
	count_rb = 0;
	size_to_push = find_size_chunk_a((*chunks)->content);
	while (push < size_to_push)
	{
		if ((intptr_t)(*stack_b)->content > median)
		{
			del_nb((*stack_b)->content, (t_list **)&(*chunks)->content);
			do_pa(s_a, stack_b, True);
			if ((intptr_t)(*s_a)->content > (intptr_t)(*s_a)->next->content)
				do_sa(s_a, True);
			push++;
		}
		else
		{
			do_rb(stack_b, True);
			count_rb++;
		}
	}
	while (count_rb-- > 0)
		do_rrb(stack_b, True);
}