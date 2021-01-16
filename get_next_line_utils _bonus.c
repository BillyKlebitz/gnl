/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:50:48 by suzumaki          #+#    #+#             */
/*   Updated: 2021/01/15 06:57:52 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int check_buffer(char *buffer);

#include "get_next_line_bonus.h"

int check_buffer(char *buffer)
{
    int i;

    i = 0;
    if (!buffer)
        return (0);
    while(buffer[i])
    {
        if (buffer[i] == '\n')
            return (1);
        i++;
    }
    return(0);
}

//size_t  ft_strlen(const char *s);

size_t  ft_strlen(const char *s)
{
    char    *ptr;
    int     res;

    res = 0;
    if(!s)
        return(res);
    ptr = (char *)s;
    while (*ptr++)
        res++;
    return (res);
}

