/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:03:43 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/14 04:37:25 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(1);
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
	write (1, "pa\n", 3);
}
