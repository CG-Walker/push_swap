/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:15 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:15 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ope_sa_sb(t_list **stack)
{
	void	*tmp_content;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp_content = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp_content;
}

void	ope_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;
	t_list	*new_begin;

	if (ft_lstsize((*stack_b)) <= 0)
		return ;
	new = ft_lstnew((*stack_b)->content);
	new_begin = (*stack_b)->next;
	free((*stack_b));
	if (new_begin)
		new_begin->previous = NULL;
	(*stack_b) = new_begin;
	ft_lstadd_front(stack_a, new);
	return ;
}

void	ope_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;
	t_list	*new_begin;

	if (ft_lstsize((*stack_a)) <= 0)
		return ;
	new = ft_lstnew((*stack_a)->content);
	new_begin = (*stack_a)->next;
	free((*stack_a));
	if (new_begin)
		new_begin->previous = NULL;
	(*stack_a) = new_begin;
	ft_lstadd_front(stack_b, new);
	return ;
}

void	ope_rab(t_list **stack)
{
	t_list	*begin;
	void	*tmp;

	begin = *stack;
	tmp = begin->content;
	while ((*stack)->next != NULL)
	{
		(*stack)->content = (*stack)->next->content;
		(*stack) = (*stack)->next;
	}
	(*stack)->content = tmp;
	(*stack) = begin;
}

void	ope_rrab(t_list **stack)
{
	t_list	*begin;
	void	*tmp;
	void	*tmp2;

	begin = *stack;
	tmp = begin->content;
	(*stack)->content = ft_lstlast(*stack)->content;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		tmp2 = (*stack)->content;
		(*stack)->content = tmp;
		tmp = tmp2;
	}
	(*stack) = begin;
}
