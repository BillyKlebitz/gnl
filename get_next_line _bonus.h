/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:54:02 by suzumaki          #+#    #+#             */
/*   Updated: 2021/01/15 13:10:54 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

typedef struct		s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

t_arr				*ft_newlist(const int fd);
int check_buffer(char *buffer);
size_t  ft_strlen(const char *s);
void    *ft_memset(void *s, int c, size_t n);
char    *get_line(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char *get_res(char *res);
int check_buffer(char *buffer);

#endif
