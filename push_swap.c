/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:17 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:17 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack, char *stack_name)
{
	t_list	*begin;

	begin = stack;
	printf("[%s] : ", stack_name);
	while (stack != NULL)
	{
		printf("%li ", (intptr_t)stack->content);
		stack = stack->next;
	}
	printf("\n");
	stack = begin;
}

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	if ((check_sorted(*stack_a)) == False)
	{
		if (ft_lstsize(*stack_a) <= 5)
			solve_5_or_less(stack_a, stack_b);
		else
			solve_half(stack_a, stack_b);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (check_all(argc, argv) == False)
	{
		printf("Error.\n");
		return (-1);
	}
	if (argc == 2)
		stack_a = init_stack_a_with_var(stack_a, argv);
	else
		stack_a = init_stack_a(stack_a, argv);
	push_swap(&stack_a, &stack_b);
	if (check_sorted(stack_a) == True)
	{
		lst_free(stack_a);
		lst_free(stack_b);
	}
	exit(0);
}
