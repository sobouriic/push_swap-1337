/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:59:55 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/14 04:29:54 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

int	check_ints(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **str, int *len)
{
	int	i;

	i = 0;
	if (!str[0])
		ft_error();
	while (str[i] != '\0')
	{
		if (!check_ints(str[i]))
			ft_error();
		i++;
	(*len)++;
	}
	return (1);
}

void	free_(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	*fill_stack(int size, char **av, int ac)
{
	int		*k;
	int		i;
	int		j;
	int		l;
	char	**args;

	k = malloc(sizeof(int) * (size));
	i = 0;
	j = 0;
	l = 0;
	while (++i < ac)
	{
		args = ft_split(av[i], ' ');
		j = 0;
		while (args[j])
		{
			k[l] = ft_atoi(args[j]);
			l++;
			j++;
		}
		free_(args);
	}
	return (k);
}

void	check_dup(t_stack *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->length_a)
	{
		j = i + 1;
		while (j < list->length_a)
		{
			if (list->stack_a[i] == list->stack_a[j])
			{
				free(list);
				ft_error();
			}
			j++;
		}
		i++;
	}
}
