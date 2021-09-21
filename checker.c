/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:51 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/09/21 17:52:49 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	do_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (instr == NULL)
		return (False);
	if (ft_strcmp(instr, "sa") == 0)
		do_sa(stack_a, False);
	else if (ft_strcmp(instr, "sb") == 0)
		do_sb(stack_b, False);
	else if (ft_strcmp(instr, "ss") == 0)
		do_ss(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "pa") == 0)
		do_pa(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "pb") == 0)
		do_pb(stack_a, stack_b, False);
	else if (ft_strcmp(instr, "ra") == 0)
		do_ra(stack_a, False);
	else if (ft_strcmp(instr, "rb") == 0)
		do_rb(stack_b, False);
	else if (ft_strcmp(instr, "rr") == 0)
		do_rr(stack_a, stack_b, False);
	else if (do_instr_2(instr, stack_a, stack_b) == True)
		return (True);
	free(instr);
	return (True);
}

t_bool	do_instr_2(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instr, "rra") == 0)
		do_rra(stack_a, False);
	else if (ft_strcmp(instr, "rrb") == 0)
		do_rrb(stack_b, False);
	else if (ft_strcmp(instr, "rrr") == 0)
		do_rrr(stack_a, stack_b, False);
	else
		return (False);
	return (True);
}

void	check_and_free(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted((*stack_a)))
		printf("OK\n");
	else
		printf("KO\n");
	lst_free((*stack_a));
	lst_free((*stack_b));
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*tmp;
	char	**instr;
	size_t	i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || check_all(argc, argv) == False)
		return (-1);
	if (argc == 2)
		stack_a = init_stack_a_with_var(stack_a, argv);
	else
		stack_a = init_stack_a(stack_a, argv);
	tmp = sh_read_line();
	instr = ft_split(tmp, '\n');
	free(tmp);
	while (True)
		if (do_instr(instr[i++], &stack_a, &stack_b) == False)
			break ;
	free(instr);
	check_and_free(&stack_a, &stack_b);
	return (0);
}
