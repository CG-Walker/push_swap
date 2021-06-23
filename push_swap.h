#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
//# include <malloc.h>
# include <limits.h>

# include "libft/libft.h"

/*
** push_swap.c
*/

int		    main(int argc, char *argv[]);
void	    print_list(t_list *stack);

/*
** init_stack_a.c
*/

t_list      *init_stack_a(t_list *stack_a, char *argv[]);
t_list      *init_stack_a_with_var(t_list *stack_a, char *argv[]);

/*
** solve_less_than_5.c
*/

void	    solve_5_or_less(t_list **stack_a, t_list **stack_b);
void	    solve_half(t_list **stack_a, t_list **stack_b);

/*
** solve_less_than_100.c
*/

void        solve_half(t_list **stack_a, t_list **stack_b);
long int	*convert_in_sorted_array(t_list *stack);

/*
** solve_utils.c
*/

long int	find_min(t_list **stack);
long int	find_big(t_list **stack);
long int	find_median(t_list *stack);

/*
** checks
*/

t_bool  	check_all(char *argv[]);
t_bool  	check_sorted(t_list *stack);

/*
** read_line
*/

char    	*sh_read_line(void);

/*
** ope
*/

void    	ope_sa_sb(t_list **stack);
void	    ope_pa(t_list **stack_a, t_list **stack_b);
void	    ope_pb(t_list **stack_a, t_list **stack_b);
void	    ope_rab(t_list **stack);
void	    ope_rrab(t_list **stack);

/*
** do_ope
*/

void	    do_sa(t_list **stack_a);
void	    do_sb(t_list **stack_b);
void	    do_ss(t_list **stack_a, t_list **stack_b);
void	    do_pa(t_list **stack_a, t_list **stack_b);
void	    do_pb(t_list **stack_a, t_list **stack_b);
void	    do_ra(t_list **stack_a);
void	    do_rb(t_list **stack_b);
void	    do_rr(t_list **stack_a, t_list **stack_b);
void    	do_rra(t_list **stack_a);
void    	do_rrb(t_list **stack_b);
void	    do_rrr(t_list **stack_a, t_list **stack_b);

#endif