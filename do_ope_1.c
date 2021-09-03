/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:06 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:06 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_list **stack_a, t_bool print)
{
	ope_sa_sb(stack_a);
	if (print == True)
		printf("sa\n");
}

void	do_sb(t_list **stack_b, t_bool print)
{
	ope_sa_sb(stack_b);
	if (print == True)
		printf("sb\n");
}

void	do_ss(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_sa_sb(stack_a);
	ope_sa_sb(stack_b);
	if (print == True)
		printf("ss\n");
}

void	do_pa(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_pa(stack_a, stack_b);
	if (print == True)
		printf("pa\n");
}

void	do_pb(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_pb(stack_a, stack_b);
	if (print == True)
		printf("pb\n");
}
