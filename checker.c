/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:15:51 by cgoncalv          #+#    #+#             */
/*   Updated: 2021/06/23 14:39:33 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
    if (ft_strcmp(instr, "sa"))
        do_sa(stack_a);
    else if (ft_strcmp(instr, "sb"))
        do_sb(stack_b);
    else if (ft_strcmp(instr, 4))
    {
        if (check_sorted((*stack_a)))
            printf("Sorted !");
        else
            printf("Not sorted.");
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