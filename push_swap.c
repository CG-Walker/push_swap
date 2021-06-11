#include "push_swap.h"

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	if ((check_sorted(*stack_a)) == False)
	{
		if (ft_lstsize(*stack_a) <= 5)
			solve_5_or_less(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) <= 100)
			solve_half(stack_a, stack_b);
	}
	return (0);
}

void	print_list(t_list *stack)
{
	t_list	*begin;

	begin = stack;
	while (stack != NULL)
	{
		printf("%li ", (intptr_t)stack->content);
		stack = stack->next;
	}
	printf("\n");
	stack = begin;
}

t_list	*init_stack_a(t_list *stack_a, char *argv[])
{
	size_t		i;
	intptr_t	nb;
	t_list		*new;

	i = 1;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		new = ft_lstnew((void *)nb);
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

t_list	*init_stack_a_with_var(t_list *stack_a, char *argv[])
{
	char	**table;

	table = ft_split(argv[1], ' ');
	stack_a = init_stack_a(stack_a, table);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (check_all(argv) == False)
	{
		printf("Error.\n");
		return (-1);
	}
	if (argc == 2 && argv[1][0] == '$')
		stack_a = init_stack_a_with_var(stack_a, argv);
	else
		stack_a = init_stack_a(stack_a, argv);
	printf("Init :\na : ");
	print_list(stack_a);
	printf("b : ");
	print_list(stack_b);
	push_swap(&stack_a, &stack_b);
	printf("\nAfter :\na : ");
	print_list(stack_a);
}
