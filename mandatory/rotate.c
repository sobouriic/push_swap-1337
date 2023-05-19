/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:36:01 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/12 10:14:42 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *str)
{
	int	i;
	int	temp;

	temp = str->stack_a[0];
	i = 0;
	while (i < str->length_a && i + 1 < str->length_a)
	{
		str->stack_a[i] = str->stack_a[i + 1];
		i++;
	}
	str->stack_a[str->length_a - 1] = temp;
	write (1, "ra\n", 3);
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
	write (1, "rb\n", 3);
}

void	rotate_a_b(t_stack *str)
{
	rotate_a(str);
	rotate_b(str);
	write (1, "rr\n", 3);
}
