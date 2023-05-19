/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:22:59 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/19 07:06:35 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	int		i;
	char	**arg;
	t_stack	*str;

	i = 0;
	if (ac == 1)
		exit(0);
	str = malloc(sizeof(t_stack));
	str->stack_b = NULL;
	str->length_a = 0;
	str->length_b = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		check_args(arg, &str->length_a);
		free_(arg);
	}
	str->stack_a = fill_stack(str->length_a, av, ac);
	check_dup(str);
	check_arg(str);
	return (0);
}
