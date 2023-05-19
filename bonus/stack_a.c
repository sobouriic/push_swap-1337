/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:52:22 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 10:08:06 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_stack_a(t_stack *list, int size)
{
	swap_stack(list->stack_a, size);
}

void	push_a(t_stack *str)
{
	int	*a;
	int	*b;

	if (str->length_b == 0)
		return ;
	str->length_a = str->length_a + 1;
	str->length_b = str->length_b - 1;
	a = malloc(sizeof(int) * str->length_a);
	if (!a)
		return ;
	b = malloc(sizeof(int) * str->length_b);
	if (!b)
		return ;
	if (str->length_b > 0 && str->stack_b != NULL)
		ft_memcpy(b, str->stack_b + 1, str->length_b * sizeof(int));
	if (str->length_a > 0 && str->stack_a != NULL)
		ft_memcpy(a + 1, str->stack_a, (str->length_a - 1) * sizeof(int));
	a[0] = str->stack_b [0];
	free(str->stack_a);
	free(str->stack_b);
	str->stack_a = a;
	str->stack_b = b;
}

void	rotate_a(t_stack *str)
{
	int	i;
	int	temp;

	if (!str->length_a)
		return ;
	temp = str->stack_a[0];
	i = 0;
	while (i < str->length_a && i + 1 < str->length_a)
	{
		str->stack_a[i] = str->stack_a[i + 1];
		i++;
	}
	str->stack_a[str->length_a - 1] = temp;
}

void	reverse_rotate_a(t_stack *str)
{
	int	i;
	int	temp;

	if (str->length_a < 2)
		return ;
	i = str->length_a - 1;
	temp = str->stack_a[str->length_a - 1];
	while (i--)
		str->stack_a[i + 1] = str->stack_a[i];
	str->stack_a[0] = temp;
}
