/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:54:19 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 10:16:26 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *list)
{
	int	i;

	i = 0;
	while (i < list->length_a - 1)
	{
		if (list->stack_a[i] > list->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sortthree(t_stack *list)
{
	if (list->stack_a[0] == get_max_value(list))
	{
		rotate_a(list);
		if (list->stack_a[0] > list->stack_a[1])
			swap_stack_a(list, list->length_a);
	}
	else if (list->stack_a[1] == get_max_value(list))
	{
		reverse_rotate_a(list);
		if (list->stack_a[0] > list->stack_a[1])
			swap_stack_a(list, list->length_a);
	}
	else if (list->stack_a[0] > list->stack_a[1])
		swap_stack_a(list, list->length_a);
}

void	sort_4(t_stack *list)
{
	check_min(list);
	push_b(list);
	sortthree(list);
	push_a(list);
}

void	sort_5(t_stack *list)
{
	check_min(list);
	push_b(list);
	sort_4(list);
	push_a(list);
}
