/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:44:43 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 10:17:38 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_stack(int *stack, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	swap_stack_a(t_stack *list, int size)
{
	swap_stack(list->stack_a, size);
	write(1, "sa\n", 3);
}

void	swap_stack_b(t_stack *list, int size)
{
	swap_stack(list->stack_b, size);
	write(1, "sb\n", 3);
}

void	swap_a_b(int *stack_a, int *stack_b, int size)
{
	swap_stack(stack_a, size);
	swap_stack(stack_b, size);
	write(1, "ss\n", 3);
}
