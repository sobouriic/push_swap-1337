/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:52:31 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 10:09:18 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_stack_b(t_stack *list, int size)
{
	swap_stack(list->stack_b, size);
}

void	push_b(t_stack *str)
{
	int	*a;
	int	*b;

	if (str->length_a == 0)
		return ;
	str->length_a = str->length_a - 1;
	str->length_b = str->length_b + 1;
	a = malloc(sizeof(int) * str->length_a);
	if (!a)
		return ;
	b = malloc(sizeof(int) * str->length_b);
	if (!b)
		return ;
	if (str->length_a > 0 && str->stack_a != NULL)
		ft_memcpy(a, str->stack_a + 1, str->length_a * sizeof(int));
	if (str->length_b > 0 && str->stack_b != NULL)
		ft_memcpy(b + 1, str->stack_b, (str->length_b - 1) * sizeof(int));
	b[0] = str->stack_a[0];
	free(str->stack_a);
	free(str->stack_b);
	str->stack_b = b;
	str->stack_a = a;
}

void	reverse_rotate_b(t_stack *str)
{
	int	i;
	int	j;
	int	temp;

	if (!str->length_b)
		return ;
	str->tab = malloc(sizeof(int) * str->length_b);
	temp = str->stack_b[str->length_b - 1];
	i = 0;
	while (i < str->length_b)
	{
		str->tab[i] = str->stack_b[i];
		i++;
	}
	i = 1;
	j = 0;
	while (i < str->length_b)
	{
		str->stack_b[i] = str->tab[j];
		i++;
		j++;
	}
	free(str->tab);
	str->stack_b[0] = temp;
}

void	rotate_b(t_stack *str)
{
	int	i;
	int	temp;

	if (!str->length_b)
		return ;
	temp = str->stack_b[0];
	i = 0;
	while (i < str->length_b && i + 1 < str->length_b)
	{
		str->stack_b[i] = str->stack_b[i + 1];
		i++;
	}
	str->stack_b[str->length_b - 1] = temp;
}
