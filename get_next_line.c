/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:34:05 by suzumaki          #+#    #+#             */
/*   Updated: 2020/12/19 18:03:57 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		res;

	res = 0;
	ptr = (char *)s;
	while (*ptr++)
		res++;
	return (res);
}


void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	int				sym;

	ptr = s;
	sym = c;
	while (n--)
		*ptr++ = sym;
	return (s);
}


char	*ft_strdup(const char *s)
{
	const char	*cps;
	char		*res;
	char		*cp_res;

	cps = s;
	if (!(res = malloc((ft_strlen(s) + 1) * sizeof(const char))))
		return (NULL);
	cp_res = res;
	while (*cps)
	{
		ft_memset(cp_res, *cps, 1);
		cp_res++;
		cps++;
	}
	ft_memset(cp_res, '\0', 1);
	return (res);
}

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;
	char *res;

	res = NULL;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			res = ptr;
		ptr++;
	}
	if (c == 0)
		res = ptr;
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;
	size_t	n;

	if ((!(s1 && s2)))
		return (NULL);
	n = 1 + ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (n))))
		return (NULL);
	res = ptr;
	while (n-- && *s1 != '\0')
		*ptr++ = *s1++;
	while (n-- && s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}


int get_next_line(int fd, char **line)
{
	char *tmp;
	static char *rmn;

	tmp = malloc((BUFFER_SIZE+1)*sizeof(char));
	ft_bzero(tmp,BUFFER_SIZE+1);
	read(fd,tmp,BUFFER_SIZE);
	if(ft_strrchr(tmp,'\n'))
		*line = ft_strdup(tmp);		
	else
	{	
		ft_strjoin(rmn,tmp);
	}
	free(tmp);
	return(0);
}


int main()
{
	char *line;
	get_next_line(1, &line);
	printf("%s",line);
}
