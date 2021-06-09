#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <malloc.h>
# include <limits.h>

# include "libft/libft.h"

/*
** push_swap
*/

int     main(int argc, char *argv[]);
void    print_list(t_list *stack);

/*
** solve.c
*/

void    solve_5_or_less(t_list **stack_a, t_list **stack_b);

/*
** checks
*/

t_bool  check_all(char *argv[]);
t_bool  check_sorted(t_list *stack);

/*
** read_line
*/

char	*sh_read_line(void);

/*
** ope
*/

void    ope_sa_sb(t_list **stack);
void    ope_pa(t_list **stack_a, t_list **stack_b);
void    ope_pb(t_list **stack_a, t_list **stack_b);
void    ope_rab(t_list **stack);
void    ope_rrab(t_list **stack);

/*
** do_ope
*/

void    do_sa(t_list **stack_a);
void    do_sb(t_list **stack_b);
void    do_ss(t_list **stack_a, t_list **stack_b);
void    do_pa(t_list **stack_a, t_list **stack_b);
void    do_pb(t_list **stack_a, t_list **stack_b);
void    do_ra(t_list **stack_a);
void    do_rb(t_list **stack_b);
void    do_rr(t_list **stack_a, t_list **stack_b);
void    do_rra(t_list **stack_a);
void    do_rrb(t_list **stack_b);
void    do_rrr(t_list **stack_a, t_list **stack_b);

#endif