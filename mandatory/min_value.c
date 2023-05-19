/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:56:03 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 09:58:10 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack *list)
{
	int	min;
	int	i;

	i = 0;
	min = list->stack_a[0];
	while (i < list->length_a)
	{
		if (min > list->stack_a[i])
			min = list->stack_a[i];
		i++;
	}
	return (min);
}

int	min_pos(t_stack *list)
{
	int	i;
	int	min;

	i = 0;
	min = get_min_value(list);
	while (1)
	{
		if (min == list->stack_a[i])
			break ;
		i++;
	}
	return (i);
}

void	check_min(t_stack *list)
{
	int	pos;

	while (1)
	{
		pos = min_pos(list);
		if (pos == 0)
			break ;
		else if (pos <= list->length_a / 2)
			rotate_a(list);
		else if (pos > list->length_a / 2)
			reverse_rotate_a(list);
	}
}
