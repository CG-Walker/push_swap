#include "push_swap.h"

long int	find_min(t_list **stack)
{
	t_list		*begin;
	long int	ret;

	ret = INT_MAX;
	begin = (*stack);
	while ((*stack) != NULL)
	{
		if ((intptr_t)(*stack)->content < ret)
			ret = (intptr_t)(*stack)->content;
		(*stack) = (*stack)->next;
	}
	(*stack) = begin;
	return (ret);
}

long int	find_big(t_list **stack)
{
	t_list		*begin;
	long int	ret;

	ret = INT_MIN;
	begin = (*stack);
	while ((*stack) != NULL)
	{
		if ((intptr_t)(*stack)->content > ret)
			ret = (intptr_t)(*stack)->content;
		(*stack) = (*stack)->next;
	}
	(*stack) = begin;
	return (ret);
}

long int	find_median(t_list *stack)
{
	size_t		size;
	long int	*array;
	
	array = convert_in_sorted_array(stack);
	
	return (array[ft_lstsize(stack)/2]);
}