#include "push_swap.h"

t_bool  check_sorted(t_list *stack)
{
    t_list *begin;

    begin = stack;
    while (stack->next != NULL)
    {
        if (stack->content > stack->next->content)
            return (False);
        stack = stack->next;
    }
    stack = begin;
    return (True);
}

static t_bool  check_double(char *argv[])
{
    size_t i;
    size_t j;
    char *tmp;

    i = 1;
    j = 1;
    while (argv[i] != NULL)
    {
        tmp = argv[i];
        j = i + 1;
        while(argv[j] != NULL)
        {
            if (tmp == argv[j])
                return (True);
            j++;
        }
        i++;
    }
    return (False);
}

static t_bool  check_args(char *argv[])
{
    size_t i;
    size_t j;

    i = 1;
    j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == False)
				return (False);
            j++;
        }
        j = 0;
        i++;
    }
    return (True);
}

t_bool  check_all(char *argv[])
{
    if (check_args(argv) == False)
        return (False);
    if (check_double(argv) == True)
        return (False);
    return (True);
}