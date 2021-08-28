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
	t_list	*tmp_list;

	tmp_list = NULL;
	while (list_to_copy != NULL)
	{
		ft_lstadd_front(&tmp_list, ft_lstnew(list_to_copy->content));
		list_to_copy = list_to_copy->next;
	}
	ft_lstadd_front(alst, ft_lstnew(tmp_list));
}

void	del_nb(void *nb, t_list **chunk)
{
	t_list	*begin;

	begin = (*chunk);
	if ((*chunk)->content == nb)
		begin = (*chunk)->next;
	while ((*chunk) && (*chunk)->next && (*chunk)->next->content != nb)
		(*chunk) = (*chunk)->next;
	if ((*chunk)->next && (*chunk)->next->next)
		(*chunk)->next = (*chunk)->next->next;
	else
		(*chunk)->next = NULL;
	(*chunk) = begin;
}