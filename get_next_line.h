/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:22:43 by suzumaki          #+#    #+#             */
/*   Updated: 2020/12/19 13:37:03 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 16
#include <unistd.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);

#endif
