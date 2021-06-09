#include "push_swap.h"

void    solve_2(t_list **stack_a)
{
    do_sa(stack_a);
}

void    solve_3(t_list **stack_a)
{
    while (check_sorted(*stack_a) != True)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
            do_sa(stack_a);
        if (check_sorted(*stack_a) != True)
            do_ra(stack_a);
    }
}

long int    find_min(t_list **stack)
{
    t_list *begin;
    long int ret;

    ret = INT_MAX;
    begin = (*stack);
    while ((*stack)->next != NULL)
    {
        if ((intptr_t)(*stack)->content < ret)
            ret = (intptr_t)(*stack)->content;
        (*stack) = (*stack)->next;
    }
    (*stack) = begin;
    return (ret);
}

void    solve_4(t_list **stack_a, t_list **stack_b)
{
    long int min;

    min = find_min(stack_a);
    while ((intptr_t)(*stack_a)->content != min)
        do_ra(stack_a);
    do_pb(stack_a, stack_b);
    solve_3(stack_a);
    do_pa(stack_a, stack_b);
    do_ra(stack_a);
}

void    solve_5(t_list **stack_a, t_list **stack_b)
{
    return ;
}

void    solve_5_or_less(t_list **stack_a, t_list **stack_b)
{
    size_t size;

    size = ft_lstsize(*stack_a);
    if (size == 2)
        solve_2(stack_a);
    else if (size == 3)
        solve_3(stack_a);
    else if (size == 4)
        solve_4(stack_a, stack_b);
    else if (size == 5)
        solve_5(stack_a, stack_b);
}

void    solve_half(t_list **stack_a, t_list **stack_b)
{
    int split;

    split = 1;

    return ;
}

/*
**  (5 6 7 10 9 8 1 3 2 4 11 12) -> 7
**  (11 12 7 10 9 8) (5 6 1 3 2 4)
**  (11 12) (5 6 1 3 2 4 7 9 8 10)
**
*/