/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:37:36 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/19 07:05:18 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *list, int length)
{
	if (length == 1)
		exit (0);
	else if (length == 2)
	{
		if (list->stack_a[0] > list->stack_a[1])
			swap_stack_a(list, list->length_a);
	}
	else if (sorted(list) == 1)
		exit (0);
	else if (length == 3)
		sortthree(list);
	else if (length == 4)
		sort_4(list);
	else if (length == 5)
		sort_5(list);
	else if (length > 5 || length <= 500)
	{
		sort(list);
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	**arg;
	t_stack	*str;

	i = 0;
	str = malloc(sizeof(t_stack));
	str->length_a = 0;
	str->length_b = 0;
	str->stack_b = NULL;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		check_args(arg, &str->length_a);
		free_(arg);
	}
	str->stack_a = fill_stack(str->length_a, av, ac);
	check_dup(str);
	str->sort_tab = bubble_sort(str);
	push_swap(str, str->length_a);
	return (0);
}
