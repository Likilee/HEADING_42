/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:56:21 by kilee             #+#    #+#             */
/*   Updated: 2020/10/16 16:15:02 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
