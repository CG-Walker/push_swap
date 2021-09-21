/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:02:02 by walker            #+#    #+#             */
/*   Updated: 2021/09/03 21:02:02 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_bool	check_min_max(char *argv[])
{
	size_t	i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (False);
		i++;
	}
	return (True);
}

t_bool	check_all(int argc, char *argv[])
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (check_args(args) == False)
	{
		printf("<Non-digit arg detected>\n");
		return (False);
	}
	if (check_double(args) == True)
	{
		printf("<Same number twice or more in list>\n");
		return (False);
	}
	if (check_min_max(args) == False)
	{
		printf("<Number(s) higher than Max Int or lower than Min Int>\n");
		return (False);
	}
	return (True);
}
