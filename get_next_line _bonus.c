/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:25:20 by suzumaki          #+#    #+#             */
/*   Updated: 2021/01/15 04:03:26 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

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

char	*get_line(const char *s)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!(rtn = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;
	size_t	n;

	if (!s1 && !s2)
		return (NULL);
	n = 1 + ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (n))))
		return (NULL);
	res = ptr;
	while (s1 && n-- && *s1 != '\0')
		*ptr++ = *s1++;
	while (n-- && *s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

char	*get_res(char *res)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!res)
		return (0);
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(res) - i) + 1))))
		return (0);
	i++;
	while (res[i])
		rtn[j++] = res[i++];
	rtn[j] = '\0';
	free(res);
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	static char	*res;
	char		*buffer;
	int			hv_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	hv_read = 1;
	while (hv_read != 0 && !check_buffer(res))
	{
		if ((hv_read = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[hv_read] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	*line = get_line(res);
	res = get_res(res);
	return (1);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *a;

	int kek = open("text.txt",O_RDONLY);
	get_next_line(kek,&a);
	printf("%s",a);	
	free(a);
	get_next_line(kek,&a);	
	printf("%s",a);
	free(a);
	close(kek);
	return (0);
}*/
