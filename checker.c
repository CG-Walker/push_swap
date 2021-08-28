/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:51 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/08/28 16:52:33 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	do_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		do_sa(stack_a, False);
	else if (ft_strcmp(instr, "sb\n") == 0)
		do_sb(stack_b, False);
	else if (ft_strcmp(instr, "ss\n") == 0)
		do_ss(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "pa\n") == 0)
		do_pa(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "pb\n") == 0)
		do_pb(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "ra\n") == 0)
		do_ra(stack_a, False);
	else if (ft_strcmp(instr, "rb\n") == 0)
		do_rb(stack_b, False);
	else if (ft_strcmp(instr, "rr\n") == 0)
		do_rr(stack_a, stack_b, False);
	else if (do_instr_2(instr, stack_a, stack_b) == True)
		return (True);
	return (False);
}

t_bool	do_instr_2(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instr, "rra\n") == 0)
		do_rra(stack_a, False);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		do_rrb(stack_b, False);
	else if (ft_strcmp(instr, "rrr\n") == 0)
		do_rrr(stack_a, stack_b, False);
	else
	{
		if (check_sorted((*stack_a)))
			printf("OK\n");
		else
			printf("KO\n");
		return (True);
	}
	return (False);
}

void	print_list(t_list *stack)
{
	t_list	*begin;

	begin = stack;
	while (stack != NULL)
	{
		printf("%li ", (intptr_t)stack->content);
		stack = stack->next;
	}
	printf("\n");
	stack = begin;
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2 && argv[1][0] == '$')
		stack_a = init_stack_a_with_var(stack_a, argv);
	else
		stack_a = init_stack_a(stack_a, argv);
	while (True)
	{
		instr = sh_read_line();
		if (do_instr(instr, &stack_a, &stack_b) == True)
			break ;
	}
	return (0);
}
