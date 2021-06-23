/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:51 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/06/23 17:30:21 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
    printf("str = %s\n", instr);
    if (ft_strcmp(instr, "sa"))
        do_sa(stack_a, False);
    else if (ft_strcmp(instr, "sb"))
        do_sb(stack_b, False);
    else if (ft_strcmp(instr, "ss"))
        do_ss(stack_a, stack_b, False);
    else if (ft_strcmp(instr, "pa"))
        do_pa(stack_a, stack_b, False);
    else if (ft_strcmp(instr, "pb"))
        do_pb(stack_a, stack_b, False);
    else if (ft_strcmp(instr, "ra"))
        do_ra(stack_a, False);
    else if (ft_strcmp(instr, "rb"))
        do_rb(stack_b, False);
    else if (ft_strcmp(instr, "rr"))
        do_rr(stack_a, stack_b, False);
    else if (ft_strcmp(instr, "rra"))
        do_rra(stack_a, False);
    else if (ft_strcmp(instr, "rrb"))
        do_rrb(stack_b, False);
    else if (ft_strcmp(instr, "rrr"))
        do_rrr(stack_a, stack_b, False);
    else
    {
        printf("ENTRY\n");
        if (check_sorted((*stack_a)))
            printf("OK\n");
        else
            printf("KO\n");
    }
}

int main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b;
    char    *instr;

	stack_a = NULL;
	stack_b = NULL;

    if (argc == 2 && argv[1][0] == '$')
		stack_a = init_stack_a_with_var(stack_a, argv);
	else
		stack_a = init_stack_a(stack_a, argv);

    while (True)
    {
        instr = sh_read_line();
        do_instr(instr, &stack_a, &stack_b);
    }
    
    return (0);
}