/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:56:21 by kilee             #+#    #+#             */
/*   Updated: 2020/10/16 14:51:48 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_c;
	unsigned const char	*src_c;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (len--)
		*(dst_c++) = *(src_c++);
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_memcpy(join, s1, len1);
	ft_memcpy(join + len1, s2, len2);
	join[len1 + len2] = '\0';
	return (join);
}

char		*ft_strndup(const char *s1, size_t len)
{
	size_t		i;
	char		*dupl;

	dupl = (char *)malloc(sizeof(char) * len + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1[i])
	{
		dupl[i] = s1[i];
		++i;
	}
	dupl[i] = '\0';
	return (dupl);
}
