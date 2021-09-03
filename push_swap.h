/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:21 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:21 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_chunks
{
	t_list			*chunk;
	struct s_list	*next;
}	t_chunks;

/*
** DEBUG
*/

void		print_list(t_list *stack);

/*
** checker.c
*/

t_bool		do_instr(char *instr, t_list **stack_a, t_list **stack_b);
t_bool		do_instr_2(char *instr, t_list **stack_a, t_list **stack_b);

/*
** checks.c
*/

t_bool		check_all(char *argv[]);
t_bool		check_sorted(t_list *stack);

/*
** do_ope.c
*/

void		do_sa(t_list **stack_a, t_bool print);
void		do_sb(t_list **stack_b, t_bool print);
void		do_ss(t_list **stack_a, t_list **stack_b, t_bool print);
void		do_pa(t_list **stack_a, t_list **stack_b, t_bool print);
void		do_pb(t_list **stack_a, t_list **stack_b, t_bool print);
void		do_ra(t_list **stack_a, t_bool print);
void		do_rb(t_list **stack_b, t_bool print);
void		do_rr(t_list **stack_a, t_list **stack_b, t_bool print);
void		do_rra(t_list **stack_a, t_bool print);
void		do_rrb(t_list **stack_b, t_bool print);
void		do_rrr(t_list **stack_a, t_list **stack_b, t_bool print);

/*
** init_stack_a.c
*/

t_list		*init_stack_a(t_list *stack_a, char *argv[]);
t_list		*init_stack_a_with_var(t_list *stack_a, char *argv[]);

/*
** ope.c
*/

void		ope_sa_sb(t_list **stack);
void		ope_pa(t_list **stack_a, t_list **stack_b);
void		ope_pb(t_list **stack_a, t_list **stack_b);
void		ope_rab(t_list **stack);
void		ope_rrab(t_list **stack);

/*
** push_swap.c
*/

int			push_swap(t_list **stack_a, t_list **stack_b);

/*
** read_line
*/

char		*sh_read_line(void);

/*
** solve_less_than_5.c
*/

void		solve_5_or_less(t_list **stack_a, t_list **stack_b);
void		solve_5(t_list **stack_a, t_list **stack_b);
void		solve_4(t_list **stack_a, t_list **stack_b);
void		solve_3(t_list **stack_a);
void		solve_2(t_list **stack_a);

/*
** solve_half.c
*/

void		solve_half(t_list **stack_a, t_list **stack_b);
void		a_to_b(t_list **stack_a, t_list **stack_b, t_list **chunks);
void		b_to_a(t_list **stack_a, t_list **stack_b, t_list **chunks);
size_t		find_size_chunk_a(t_list *stack);
size_t		find_size_chunk_b(t_list *stack);
size_t		a_to_b_ope(t_list **stack_a, t_list **stack_b,
				t_list **chunk, long int median);
void		b_to_a_ope(t_list **s_a, t_list **stack_b,
				t_list **chunks, long int median);
void		free_chunks(t_list **chunks);

/*
** solve_half_utils.c
*/

long int	*sort_array(long int *array, size_t size);
long int	*convert_in_array(t_list *stack);
void		lst_copy(t_list **alst, t_list *list_to_copy);
void		del_nb(void *nb, t_list **chunk);
void		lst_free(t_list *list);

/*
** solve_utils.c
*/

long int	find_min(t_list **stack);
long int	find_big(t_list **stack);
long int	find_median(t_list *stack);

#endif