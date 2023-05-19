/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:38:25 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/17 07:01:14 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sorted(t_stack *list)
{
	int	i;

	i = 0;
	while (i < list->length_a - 1)
	{
		if (list->stack_a[i] > list->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(1);
}

void	check_comp(t_stack *list, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_stack_a(list, list->length_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_stack_b(list, list->length_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a(list);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b(list);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_a(list);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_b(list);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate_b(list);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate_a(list);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_a_b(list->stack_a, list->stack_b, list->length_a, list->length_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		reverse_rotate_a_b(list);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_a_b(list);
	else
		ft_error();
}

void	check_arg(t_stack *list)
{
	char	*k;

	while (1)
	{
		k = get_next_line(0);
		if (k == NULL)
			break ;
		check_comp(list, k);
		free(k);
	}
	if (sorted(list) == 1 && !list->length_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
