/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:34:05 by suzumaki          #+#    #+#             */
/*   Updated: 2020/12/24 20:51:44 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}


void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}



void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char	*ft_strcat(char *restrict str1, const char *restrict str2)
{
	char *tmp;

	tmp = str1;
	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (tmp);
}


char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *cpy_dest;
	unsigned char *cpy_src;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
		*cpy_dest++ = *cpy_src++;
	return (dest);
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
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

t_arr *newlist(const int fd)
{
	t_arr *new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFFER_SIZE);
	new->next = NULL;
	return (new);
}

char *checkrest(char **p_n, char *rest)
{
	char *str;

	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
	{
		str = (ft_strsub(rest, 0, *p_n - rest));
		ft_strcpy(rest, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strlcat(str, rest,1000);
		ft_strclr(rest);
	}
	return (str);

}


int get_line(const int fd, char **line, char *rest)
{
	char	buf[BUFFER_SIZE+1];
	char	*p_n;
	char	*tmp;
	int rd;

	p_n = NULL;
	rd = 1;
	*line = checkrest(&p_n, rest);
	while (p_n == 0 && ((rd = read(fd,buf, BUFFER_SIZE))) != 0)
	{
		buf[rd] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		//ft_strdel(&tmp);
		free(tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr			*tmp;
	int				ret;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}
