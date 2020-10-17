#ifndef MY_HEADER_H
# define MY_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# ifndef LEGO
#  define LEGO 32
# endif

# ifndef MAN
#  define MAN 1024
# endif

typedef struct		SAMPLE
{
	void			*content;
	struct s_list	*next;
}					sample_list;

char	*ft_strnstr(const char *target, const char *src, size_t target_len);
int		ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strndup(const char *s1, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int		ft_isascii(int c);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void			ft_strfree(char **str);
int				ft_cut_to_line(char **room, char **line);
int				ft_output(char **room, char **line, int read_val);
int				get_next_line(int fd, char **line);
int		ft_isprint(int c);
int		ft_toupper(int c);
static size_t	ft_word_size(char const *s, char c);
static size_t	ft_word_amount(char const *s, char c);
static char		*ft_strndup(const char *s, size_t n);
static void		ft_free_arr(char **s, int i);
char			**ft_split(char const *s, char c);
int		ft_isalpha(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_arr_free(char **arr);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s1);
int		ft_isalnum(int c);

#endif
