#include "push_swap.h"

size_t	find_size_chunk_a(t_list *stack)
{
	long int	*array;
	long int	median;
	size_t		i;

	i = 0;
	array = convert_in_array(stack);
	array = sort_array(array, ft_lstsize(stack));
	median = array[ft_lstsize(stack) / 2];
	while (array[i] != median)
		i++;
	if (ft_lstsize(stack) % 2 == 0)
		return (i - 1);
	else
		return (i);
}

size_t	find_size_chunk_b(t_list *stack)
{
	long int	*array;
	long int	median;
	size_t		i;

	i = 0;
	array = convert_in_array(stack);
	array = sort_array(array, ft_lstsize(stack));
	median = array[ft_lstsize(stack) / 2];
	while (array[i] != median)
		i++;
	if (ft_lstsize(stack) % 2 == 0)
		return (ft_lstsize(stack) - i);
	else
		return (ft_lstsize(stack) - i - 1);
}

void	a_to_b_ope(t_list **stack_a, t_list **stack_b, t_list *chunk, long int median, size_t push)
{
	if ((intptr_t)(*stack_a)->content < median)
	{
		ft_lstadd_back(&chunk, ft_lstnew((*stack_a)->content));
		do_pb(stack_a, stack_b, True);
		push++;
	}
	else if ((intptr_t)ft_lstlast((*stack_a))->content < median)
		do_rra(stack_a, True);
	else
		do_ra(stack_a, True);
}

void	a_to_b(t_list **stack_a, t_list **stack_b, t_list **chunks)
{
	long int	median;
	size_t		size_to_push;
	size_t		push;
	t_list		*chunk;

	chunk = NULL;
	push = 0;
	while (check_sorted((*stack_a)) == False)
	{
		median = find_median((*stack_a));
		size_to_push = find_size_chunk_b((*stack_a));
		while (push < size_to_push && check_sorted((*stack_a)) == False)
			a_to_b_ope(stack_a, stack_b, chunk, median, push);
		push = 0;
		lst_copy(chunks, chunk);
		free(chunk);
		chunk = NULL;
		if ((intptr_t)(*stack_a)->content > (intptr_t)(*stack_a)->next->content)
			do_sa(stack_a, True);
	}
}

void	b_to_a(t_list **stack_a, t_list **stack_b, t_list **chunks)
{
	long int	median;
	size_t		size_to_push;
	size_t		push;
	size_t		count_rb;

	count_rb = 0;
	while (ft_lstsize((*stack_b)) > 2)
	{
		while (ft_lstsize((*chunks)->content) > 2)
		{
			push = 0;
			median = find_median((*chunks)->content);
			size_to_push = find_size_chunk_a((*chunks)->content);
			while (push < size_to_push)
			{
				if ((intptr_t)(*stack_b)->content > median)
				{
					del_nb((*stack_b)->content, (t_list **)&(*chunks)->content);
					do_pa(stack_a, stack_b, True);
					if ((intptr_t)(*stack_a)->content > (intptr_t)(*stack_a)->next->content)
						do_sa(stack_a, True);
					push++;
				}
				else
				{
					do_rb(stack_b, True);
					count_rb++;
				}
			}
			while (count_rb > 0)
			{
				do_rrb(stack_b, True);
				count_rb--;
			}
			if (check_sorted((*stack_a)) == False)
			{
				print_list((*stack_a));
				a_to_b(stack_a, stack_b, chunks);
			}
		}
		if (ft_lstsize((*chunks)->content) == 2)
		{
			if ((intptr_t)(*stack_b)->content < (intptr_t)(*stack_b)->next->content)
				do_sb(stack_b, True);
			do_pa(stack_a, stack_b, True);
			do_pa(stack_a, stack_b, True);
		}
		else if (ft_lstsize((*chunks)->content) != 0)
			do_pa(stack_a, stack_b, True);
		(*chunks) = (*chunks)->next;
	}
}

void	solve_half(t_list **stack_a, t_list **stack_b)
{
	t_list	*chunks;

	chunks = NULL;
	a_to_b(stack_a, stack_b, &chunks);
	b_to_a(stack_a, stack_b, &chunks);
}
