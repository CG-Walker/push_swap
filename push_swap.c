#include "push_swap.h"

int push_swap()
{
    return (0);
}

void    print_list(t_list *stack)
{
    t_list *begin;

    begin = stack;
    while (stack != NULL)
    {
        printf("%li ", (intptr_t)stack->content);
        stack = stack->next;
    }
    printf("\n");
    stack = begin;
}

t_list    *init_list(t_list *stack_a, char *argv[])
{
    size_t i;
    intptr_t nb;
    t_list *new;

    i = 1;
    while (argv[i])
    {
        nb = ft_atoi(argv[i]);
        new = ft_lstnew((void *)nb);
        ft_lstadd_back(&stack_a, new);
        i++;
    }
    print_list(stack_a);
    return (stack_a);
}

t_list    *init_list_var(t_list *stack_a, char *argv[])
{
	char **table;

    table = ft_split(argv[1], ' ');
    stack_a = init_list(stack_a, table);
	return (stack_a);
}

int     main(int argc, char *argv[])
{
    t_list *stack_a;
    //t_list *stack_b;

    stack_a = NULL;

    if (argc < 2)
        return (-1);
    if (check_all(argv) == False)
    {
        printf("Error.\n");
        return (-1);
    }
	if (argc == 2 && argv[1][0] == '$')
		stack_a = init_list_var(stack_a, argv);
	else
		stack_a = init_list(stack_a, argv);
    if (check_sorted(stack_a) == True)
        printf("Stack is sorted !\n");
    //push_swap();
}