#include "push_swap.h"

void	do_rra(t_list **stack_a, t_bool print)
{
	ope_rrab(stack_a);
	if (print == True)
		printf("rra\n");
}

void	do_rrb(t_list **stack_b, t_bool print)
{
	ope_rrab(stack_b);
	if (print == True)
		printf("rrb\n");
}

void	do_rrr(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_rrab(stack_a);
	ope_rrab(stack_b);
	if (print == True)
		printf("rrr\n");
}
