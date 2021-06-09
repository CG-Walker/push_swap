#include "push_swap.h"

void    do_sa(t_list **stack_a)
{
    ope_sa_sb(stack_a);
    printf("sa\n");
}

void    do_sb(t_list **stack_b)
{
    ope_sa_sb(stack_b);
    printf("sb\n");
}

void    do_ss(t_list **stack_a, t_list **stack_b)
{
    ope_sa_sb(stack_a);
    ope_sa_sb(stack_b);
    printf("ss\n");
}

void    do_pa(t_list **stack_a, t_list **stack_b)
{
    ope_pa(stack_a, stack_b);
    printf("pa\n");
}

void    do_pb(t_list **stack_a, t_list **stack_b)
{
    ope_pb(stack_a, stack_b);
    printf("pb\n");
}

void    do_ra(t_list **stack_a)
{
    ope_rab(stack_a);
    printf("ra\n");
}

void    do_rb(t_list **stack_b)
{
    ope_rab(stack_b);
    printf("rb\n");
}

void    do_rr(t_list **stack_a, t_list **stack_b)
{
    ope_rab(stack_a);
    ope_rab(stack_b);
    printf("rr\n");
}

void    do_rra(t_list **stack_a)
{
    ope_rrab(stack_a);
    printf("rra\n");
}

void    do_rrb(t_list **stack_b)
{
    ope_rrab(stack_b);
    printf("rrb\n");
}

void    do_rrr(t_list **stack_a, t_list **stack_b)
{
    ope_rrab(stack_a);
    ope_rrab(stack_b);
    printf("rrr\n");
}