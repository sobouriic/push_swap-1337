/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:54:11 by sobouric          #+#    #+#             */
/*   Updated: 2022/11/01 20:34:43 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	ch;

	ch = (char)c;
	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == ch)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
