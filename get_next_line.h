/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:22:43 by suzumaki          #+#    #+#             */
/*   Updated: 2020/12/24 19:52:07 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_arr
{
	int			fd;
	char		*rest;
	struct s_arr	*next;
}				t_arr;

t_arr	*ft_newlist(const int fd);
char *checkrest(char **p_n, char *rest);
int get_line(const int fd, char **line, char *rest);
int get_next_line(int fd, char **line);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 16

#endif
