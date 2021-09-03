/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:08 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:08 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_list **stack_a, t_bool print)
{
	ope_rab(stack_a);
	if (print == True)
		printf("ra\n");
}

void	do_rb(t_list **stack_b, t_bool print)
{
	ope_rab(stack_b);
	if (print == True)
		printf("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_rab(stack_a);
	ope_rab(stack_b);
	if (print == True)
		printf("rr\n");
}
