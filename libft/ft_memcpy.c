/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:18:21 by sobouric          #+#    #+#             */
/*   Updated: 2022/11/02 22:38:13 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srrc;
	size_t			i;

	dest = (unsigned char *)dst;
	srrc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = srrc[i];
		i++;
	}
	return (dest);
}
