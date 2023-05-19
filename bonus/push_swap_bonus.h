/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:23:40 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/14 03:57:03 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include"../libft/libft.h"
# include"get_next_line.h"

typedef struct push_swap_bonus
{
	int	*stack_a;
	int	*stack_b;
	int	length_a;
	int	length_b;
	int	*tab;
}t_stack;

int		check_ints(char *str);
int		check_args(char **str, int *len);
void	check_arg(t_stack *list);
void	check_comp(t_stack *list, char *arr);
int		sorted(t_stack *list);
void	swap_stack_a(t_stack *list, int size);
void	push_a(t_stack *str);
void	rotate_a(t_stack *str);
void	reverse_rotate_a(t_stack *str);
void	swap_stack_b(t_stack *list, int size);
void	push_b(t_stack *str);
void	reverse_rotate_b(t_stack *str);
void	rotate_b(t_stack *str);
void	ft_swap(int	*a, int *b);
void	swap_stack(int *stack, int size);
void	reverse_rotate_a_b(t_stack *str);
void	rotate_a_b(t_stack *str);
void	free_(char	**arr);
int		*fill_stack(int size, char **av, int ac);
void	check_dup(t_stack *list);
void	swap_a_b(int *stack_a, int *stack_b, int size_a, int size_b);
void	ft_error(void);
#endif