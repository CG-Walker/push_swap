/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:34:36 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:55 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack_a(t_list *stack_a, char *argv[])
{
	size_t		i;
	intptr_t	nb;
	t_list		*new;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		new = ft_lstnew((void *)nb);
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

t_list	*init_stack_a_with_var(t_list *stack_a, char *argv[])
{
	char	**table;
	size_t	i;

	i = 0;
	table = ft_split(argv[1], ' ');
	stack_a = init_stack_a(stack_a, table);
	while (table[i])
		free(table[i++]);
	free(table);
	return (stack_a);
}
