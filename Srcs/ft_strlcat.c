/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:44:18 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/19 17:36:04 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long		i;
	unsigned long		src_len;
	unsigned long		dst_len;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		++dst_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
