/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:46 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:46 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	find_min(t_list **stack)
{
	t_list		*begin;
	long int	ret;

	ret = INT_MAX;
	begin = (*stack);
	while ((*stack) != NULL)
	{
		if ((intptr_t)(*stack)->content < ret)
			ret = (intptr_t)(*stack)->content;
		(*stack) = (*stack)->next;
	}
	(*stack) = begin;
	return (ret);
}

long int	find_big(t_list **stack)
{
	t_list		*begin;
	long int	ret;

	ret = INT_MIN;
	begin = (*stack);
	while ((*stack) != NULL)
	{
		if ((intptr_t)(*stack)->content > ret)
			ret = (intptr_t)(*stack)->content;
		(*stack) = (*stack)->next;
	}
	(*stack) = begin;
	return (ret);
}

long int	find_median(t_list *stack)
{
	long int	*array;
	long int	ret;

	array = convert_in_array(stack);
	array = sort_array(array, ft_lstsize(stack));
	ret = array[ft_lstsize(stack) / 2];
	free(array);
	return (ret);
}
