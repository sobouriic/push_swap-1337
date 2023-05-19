/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <sobouric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:36:29 by sobouric          #+#    #+#             */
/*   Updated: 2023/05/16 09:45:16 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	size_t	result;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' )
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - 48;
		if ((signe > 0 && result > 2147483647)
			|| (signe < 0 && result > 2147483648))
			ft_error();
	}
	return (result * signe);
}
