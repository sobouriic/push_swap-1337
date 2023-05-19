/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:43:15 by sobouric          #+#    #+#             */
/*   Updated: 2022/11/29 23:46:38 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_srch( char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	str = (char *) s;
	ch = (char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}

size_t	ft_strrlen( char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			i++;
		}
		return (i);
	}
	return (0);
}

char	ft_copy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst[i]);
}

char	*ft_strj(char *s1, char *s2)
{
	int		l;
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strrlen(s1);
	len2 = ft_strrlen(s2);
	l = len1 + len2;
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_copy(str, s1);
		str = str + len1;
	}
	if (s2)
	{
		ft_copy(str, s2);
		str = str + len2;
	}	
	str = str - l;
	free(s1);
	return (str);
}
