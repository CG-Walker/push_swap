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

long int	*convert_in_sorted_array(t_list *stack)
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
	array = sort_array(array, size);
	return (array);
}

void	solve_half(t_list **stack_a, t_list **stack_b)
{
	long int	median;
	long int	min;
	t_list		*begin;

	begin = (*stack_a);
	median = find_median((*stack_a));
	printf("median : %li\n", median);
	while ((*stack_a) != NULL)
	{
		if ((intptr_t)(*stack_a)->content != median)
			do_pb(stack_a, stack_b, True);
		else
			do_ra(stack_a, True);
	}
	printf("__test__\n");
	while ((*stack_b) != NULL)
	{
		printf("__test__\n");
		min = find_min(stack_b);
		while ((intptr_t)(*stack_b)->content != min)
			do_ra(stack_a, True);
		do_pa(stack_a, stack_b, True);
	}
	return ;
}