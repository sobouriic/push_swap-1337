/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:20:38 by sobouric          #+#    #+#             */
/*   Updated: 2022/11/02 01:15:49 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	size_t	j;
	size_t	i;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (i > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
	{
			str[j] = s[i];
			j++;
			i++;
	}
	str[j] = '\0';
	return (str);
}
