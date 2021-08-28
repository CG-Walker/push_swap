#include "push_swap.h"

long int	*sort_array(long int *array, size_t size)
{
	size_t		i;
	size_t		j;
	long int	tmp;

	i = 0;
	j = 1;
	while (i < (size - 1))
	{
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	i = 0;
	return (array);
}

long int	*convert_in_array(t_list *stack)
{
	long int	*array;
	size_t		i;
	size_t		size;
	t_list		*begin;

	begin = stack;
	i = 0;
	size = ft_lstsize(stack);
	array = malloc(sizeof(long int) * size);
	if (array == NULL)
		return (NULL);
	while (stack != NULL)
	{
		array[i] = (intptr_t)stack->content;
		stack = stack->next;
		i++;
	}
	stack = begin;
	return (array);
}

void	lst_copy(t_list **alst, t_list *list_to_copy)
{
	t_list *tmp_list = NULL;
	while (list_to_copy != NULL)
	{
		ft_lstadd_front(&tmp_list, ft_lstnew(list_to_copy->content));
		//free(list_to_copy->content);
		//free(list_to_copy);
		list_to_copy = list_to_copy->next;
	}
	ft_lstadd_front(alst, ft_lstnew(tmp_list));
}

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

void	del_nb(void *nb, t_list **chunk)
{
	t_list *begin;

	begin = (*chunk);
	//printf("__test__\nnb : %li\n", (intptr_t)nb);
	//print_list((*chunk));
	if ((*chunk)->content == nb)
	{
		begin = (*chunk)->next;
	}
	while ((*chunk) && (*chunk)->next && (*chunk)->next->content != nb)
	{
		//printf("c : %li c->next : %li\n", (intptr_t)(*chunk)->content, (intptr_t)(*chunk)->next->content);
		(*chunk) = (*chunk)->next;
	}

	//chunk->next = NULL;
	//printf("__test2__\n");
	if ((*chunk)->next && (*chunk)->next->next)
		(*chunk)->next = (*chunk)->next->next;
	else
		(*chunk)->next = NULL;
	//free(chunk->next->content);

	(*chunk) = begin;
	//printf("new_chunk : ");
	//print_list((*chunk));
}

void	a_to_b(t_list **stack_a, t_list **stack_b, t_list **chunks)
{
	long int	median;
	size_t		size_to_push;
	size_t		push;
	t_list		*chunk;

	chunk = NULL;
	push = 0;
	//printf("__A_TO_B__\n");
	while (check_sorted((*stack_a)) == False)
	{
		median = find_median((*stack_a));
		size_to_push = find_size_chunk_b((*stack_a));
		while (push < size_to_push && check_sorted((*stack_a)) == False)
		{
		/* 	printf("a : ");
			print_list((*stack_a));
			printf("Median : %li\n", median); */
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
		push = 0;
		lst_copy(chunks, chunk);
		free(chunk);
		chunk = NULL;
		//size_to_push = ft_lstsize((*stack_a));
		if ((intptr_t)(*stack_a)->content > (intptr_t)(*stack_a)->next->content)
			do_sa(stack_a, True);
		//sleep(1);
	}
}

void	b_to_a(t_list **stack_a, t_list **stack_b, t_list **chunks)
{
	long int	median;
	size_t		size_to_push;
	size_t		push;
	size_t		count_rb;

	count_rb = 0;
	//printf("__B_TO_A__\n");
	while (ft_lstsize((*stack_b)) > 2)
	{
		//printf("chunks->content : %li\n", ft_lstsize((*chunks)->content));
		while (ft_lstsize((*chunks)->content) > 2)
		{
			push = 0;
			median = find_median((*chunks)->content);
			size_to_push = find_size_chunk_a((*chunks)->content);
			/* printf("median : %li\n", median);
			printf("size_to_push : %li\n", size_to_push);
			printf("nb : %li\n", (intptr_t)(*stack_b)->content);
			printf("c : ");
			print_list((*chunks)->content);
			printf("b : ");
			print_list((*stack_b));
			printf("a : ");
			print_list((*stack_a)); */
			while (push < size_to_push)
			{
				//printf("nb : %li -> ", (intptr_t)(*stack_b)->content);
				if ((intptr_t)(*stack_b)->content > median)
				{
					del_nb((*stack_b)->content, &(*chunks)->content);
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
				//sleep(1);
			}
			while (count_rb > 0)
			{
				do_rrb(stack_b, True);
				count_rb--;
			}
			if (check_sorted((*stack_a)) == False)
			{
				//printf("From b :\na : ");
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
