/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_half_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:53:28 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 20:55:32 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*sort_array(long int *array, size_t size)
{
	size_t		i;
	size_t		j;
	long int	tmp;

	i = 0;
	j = 1;
	while (i < (size - 1))
	{
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	i = 0;
	return (array);
}

long int	*convert_in_array(t_list *stack)
{
	long int	*array;
	size_t		i;
	size_t		size;
	t_list		*begin;

	begin = stack;
	i = 0;
	size = ft_lstsize(stack);
	array = malloc(sizeof(long int) * size);
	if (array == NULL)
		return (NULL);
	while (stack != NULL)
	{
		array[i] = (intptr_t)stack->content;
		stack = stack->next;
		i++;
	}
	stack = begin;
	return (array);
}

void	lst_free(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	free(list);
}

void	lst_copy(t_list **alst, t_list *list_to_copy)
{
	t_list	*tmp_list;
	t_list	*begin;
	t_list	*tmp;

	begin = list_to_copy;
	tmp_list = NULL;
	tmp = NULL;
	while (list_to_copy != NULL)
	{
		tmp = ft_lstnew(list_to_copy->content);
		ft_lstadd_front(&tmp_list, tmp);
		list_to_copy = list_to_copy->next;
	}
	ft_lstadd_front(alst, ft_lstnew(tmp_list));
	list_to_copy = begin;
	lst_free(list_to_copy);
}

void	del_nb(void *nb, t_list **chunk)
{
	t_list	*begin;
	t_list	*to_free;

	begin = (*chunk);
	to_free = NULL;
	if ((*chunk)->content == nb)
	{
		to_free = (*chunk);
		begin = (*chunk)->next;
	}
	while ((*chunk) && (*chunk)->next && (*chunk)->next->content != nb)
		(*chunk) = (*chunk)->next;
	if ((*chunk)->next && (*chunk)->next->next)
	{
		to_free = (*chunk)->next;
		(*chunk)->next = (*chunk)->next->next;
	}
	else
	{
		if ((*chunk)->next)
			to_free = (*chunk)->next;
		(*chunk)->next = NULL;
	}
	free(to_free);
	(*chunk) = begin;
}
