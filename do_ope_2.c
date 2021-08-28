#include "push_swap.h"

void	do_ra(t_list **stack_a, t_bool print)
{
	ope_rab(stack_a);
	if (print == True)
		printf("ra\n");
}

void	do_rb(t_list **stack_b, t_bool print)
{
	ope_rab(stack_b);
	if (print == True)
		printf("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b, t_bool print)
{
	ope_rab(stack_a);
	ope_rab(stack_b);
	if (print == True)
		printf("rr\n");
}
