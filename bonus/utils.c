/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:21:26 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 10:39:07 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

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

void	swap_a_b(int *stack_a, int *stack_b, int size_a, int size_b)
{
	swap_stack(stack_a, size_a);
	swap_stack(stack_b, size_b);
}

void	reverse_rotate_a_b(t_stack *str)
{
	if (!str->length_a || !str->length_b)
		return ;
	reverse_rotate_a(str);
	reverse_rotate_b(str);
}

void	rotate_a_b(t_stack *str)
{
	rotate_a(str);
	rotate_b(str);
}
