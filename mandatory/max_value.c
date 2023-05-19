/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:44:11 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 09:57:56 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_max_value(t_stack *list)
{
	int	max;
	int	i;

	i = 0;
	max = list->stack_a[0];
	while (i < list->length_a)
	{
		if (max < list->stack_a[i])
			max = list->stack_a[i];
		i++;
	}
	return (max);
}

int	get_max_value_b(t_stack *list)
{
	int	max;
	int	i;

	i = 0;
	max = list->stack_b[0];
	while (i < list->length_b)
	{
		if (max < list->stack_b[i])
			max = list->stack_b[i];
		i++;
	}
	return (max);
}

int	max_pos(t_stack *list)
{
	int	i;
	int	max;

	i = 0;
	max = get_max_value_b(list);
	while (1)
	{
		if (max == list->stack_b[i])
			break ;
		i++;
	}
	return (i);
}

void	check_max(t_stack *list)
{
	int	pos;

	while (1)
	{
		pos = max_pos(list);
		if (pos == 0)
			break ;
		else if (pos <= list->length_b / 2)
			rotate_b(list);
		else if (pos > list->length_b / 2)
			reverse_rotate_b(list);
	}	
}
