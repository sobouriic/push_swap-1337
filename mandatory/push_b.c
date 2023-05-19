/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:49:07 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 09:58:19 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(str->stack_b);
	free(str->stack_a);
	str->stack_b = b;
	str->stack_a = a;
	write (1, "pb\n", 3);
}
