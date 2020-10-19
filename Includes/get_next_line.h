/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:49:10 by kihoonlee         #+#    #+#             */
/*   Updated: 2020/10/20 08:48:42 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** Define BUFFER_SIZE when doesn't define during compile
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/*
** Define OPEN_MAX when can't include <limits.h>
*/
# ifndef OPEN_MAX
#  define OPEN_MAX 12800
# endif

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		*ft_memcpy(void *dst, const void *src, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strndup(const char *s1, size_t len);
int			get_next_line(int fd, char **line);

#endif
