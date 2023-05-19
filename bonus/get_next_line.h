/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:42:56 by sobouric          #+#    #+#             */
/*   Updated: 2022/11/29 23:51:28 by sobouric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

char	*ft_strj(char *s1, char *s2);
size_t	ft_strrlen( char *str);
char	*ft_read_add(int fd, char *str);
char	*ft_nline(char *sttr);
char	ft_copy(char *dst, char *src);
char	*ft_srch( char *str, int c);
char	*get_next_line(int fd);
char	*ft_ch(char *str);
#endif
