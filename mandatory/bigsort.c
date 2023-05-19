/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:26:38 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/19 07:01:43 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(t_stack *list)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * list->length_a);
	ft_memcpy(arr, list->stack_a, list->length_a * sizeof(int));
	i = 0;
	while (i < (list->length_a - 1))
	{
		if (arr[i] > arr[i + 1])
		{
			ft_swap(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	list->len_tab = list->length_a;
	list->sort_tab = arr;
	return (arr);
}

void	sort_bigg(t_stack *list, int chunk)
{
	int	i;

	i = 0;
	while (list->length_a)
	{
		if (list->stack_a[0] <= list->sort_tab[i])
		{
			push_b(list);
			rotate_b(list);
			i++;
		}
		else if (list-> stack_a[0] > list->sort_tab[i]
			&& list->stack_a[0] <= list->sort_tab[chunk + i])
		{
			push_b(list);
			i++;
		}
		else
		{
			rotate_a(list);
		}
	}
}

void	sort(t_stack *list)
{
	int	range;
	int	size;

	range = 0;
	size = list->length_a;
	if (size >= 6 && size <= 16)
		range = 3;
	else if (size <= 100)
		range = 18;
	else
		range = 35;
	sort_bigg(list, range);
	while (list->length_b)
	{
		check_max(list);
		push_a(list);
	}
}
