/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:12:24 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 10:39:30 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *str)
{
	int	i;
	int	temp;

	i = str->length_a - 1;
	temp = str->stack_a[str->length_a - 1];
	while (i--)
		str->stack_a[i + 1] = str->stack_a[i];
	str->stack_a[0] = temp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *str)
{
	int	i;
	int	temp;

	if (str->length_b < 2)
		return ;
	i = str->length_b - 1;
	temp = str->stack_b[str->length_b - 1];
	while (i--)
		str->stack_b[i + 1] = str->stack_b[i];
	str->stack_b[0] = temp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack *str)
{
	reverse_rotate_a(str);
	reverse_rotate_b(str);
}
