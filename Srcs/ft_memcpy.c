/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:14:45 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/19 17:30:44 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
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
