/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:08:59 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 23:50:11 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include"../libft/libft.h"

typedef struct push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	*tab;
	int	length_a;
	int	length_b;
	int	size;
	int	*sort_tab;
	int	len_tab;
	int	i;
	int	j;
}t_stack;

void	reverse_rotate_a(t_stack *str);
void	reverse_rotate_b(t_stack *str);
void	rotate_a(t_stack *str);
void	swap_stack(int	*stack, int size);
void	push_b(t_stack *str);
void	rotate_b(t_stack *str);
void	push_a(t_stack *str);
void	sort_4(t_stack *list);
void	swap_a_b(int *stack_a, int *stack_b, int size);
int		check_ints(char *str);
int		check_args(char **str, int *len);
void	sortthree(t_stack *list);
void	swap_stack_a(t_stack *list, int size);
void	swap_stack_b(t_stack *list, int size);
int		min_pos(t_stack *list);
int		get_min_value(t_stack *list);
int		get_max_value(t_stack *list);
void	check_min(t_stack *list);
void	sort_5(t_stack *list);
int		sorted(t_stack *list);
int		*bubble_sort(t_stack *list);
void	push_swap(t_stack *list, int length);
void	ft_swap(int	*a, int *b);
void	sort_bigg(t_stack *list, int chunk);
void	sort(t_stack *list);
void	check_max(t_stack *list);
void	free_(char **arr);
int		*fill_stack(int size, char **av, int ac);
void	check_dup(t_stack *list);
void	ft_error(void);
#endif