/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:43:22 by sobouric          #+#    #+#             */
/*   Updated: 2022/12/02 23:12:25 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read_add(int fd, char *str)
{
	char	*buffer;
	int		nb;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb = 1;
	while (ft_srch(str, '\n') == 0 && nb != '\0')
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			if (str)
				free(str);
			return (0);
		}
		buffer[nb] = '\0';
		str = ft_strj(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_nline(char *sttr)
{
	char	*s;
	int		i;

	i = 0;
	if (!sttr[i])
		return (NULL);
	while (sttr[i] != '\0' && sttr[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (sttr[i] != '\0' && sttr[i] != '\n')
	{
		s[i] = sttr[i];
		i++;
	}
	if (sttr[i] == '\n')
	{
		s[i] = sttr[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_ch(char *s)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	a = (char *)malloc(sizeof(char) * (ft_strrlen(s)) - i + 1);
	if (a == NULL)
		return (NULL);
	i++;
	j = 0;
	while (s[i] != '\0')
		a[j++] = s[i++];
	a[j] = '\0';
	free(s);
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_add(fd, str);
	if (str == 0)
		return (0);
	line = ft_nline(str);
	str = ft_ch(str);
	return (line);
}
