#include "push_swap.h"

t_bool	check_sorted(t_list *stack)
{
	t_list	*begin;

	begin = stack;
	if (ft_lstsize(stack) <= 0)
		return (False);
	while (stack->next != NULL)
	{
		if ((intptr_t)stack->content > (intptr_t)stack->next->content)
			return (False);
		stack = stack->next;
	}
	stack = begin;
	return (True);
}

static t_bool	check_double(char *argv[])
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 1;
	j = 1;
	while (argv[i] != NULL)
	{
		tmp = argv[i];
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[j], tmp) == 0)
				return (True);
			j++;
		}
		i++;
	}
	return (False);
}

static t_bool	check_args(char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != '-' &&
			ft_isdigit(argv[i][j]) == False && argv[i][j] != ' ')
				return (False);
			j++;
		}
		j = 0;
		i++;
	}
	return (True);
}

t_bool	check_all(char *argv[])
{
	if (check_args(argv) == False)
	{
		printf("<Non-digit arg detected>\n");
		return (False);
	}
	if (check_double(argv) == True)
	{
		printf("<Same number twice or more in list>\n");
		return (False);
	}
	return (True);
}
