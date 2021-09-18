#include "push_swap.h"

void	display_chunk(t_list **chunks)
{
	size_t	i;
	t_list	*start;

	i = 0;
	start = *chunks;
	*chunks = ft_lstfirst(*chunks);
	while (*chunks)
	{
		printf("[%ld](%p) (Prev : %p) (Next : %p)\n", i, (*chunks), (*chunks)->previous, (*chunks)->next);
		print_list((*chunks)->content, "Chunks");
		i++;
		*chunks = (*chunks)->next;
	}
	*chunks = start;
}

void	print_list(t_list *stack, char *stack_name)
{
	t_list	*begin;

	begin = stack;
	printf("[%s] : ", stack_name);
	while (stack != NULL)
	{
		printf("%li ", (intptr_t)stack->content);
		stack = stack->next;
	}
	printf("\n");
	stack = begin;
}
