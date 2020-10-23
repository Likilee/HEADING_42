#ifndef HEADING_42_H
# define HEADING_42_H

# include <stdio.h>
# include "libft.h"

# ifndef HEADING
#  define HEADING 42
# endif

int		need_align(char *line);
int		not_first_line(char *line);
int		find_align_point(int fd);
int		do_align(int fd, int align_point);
void	ft_arr_free(char **arr);
int		ft_isalpha(int c);
void	*ft_memccpy(void *dst, void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s1, size_t len);
char	*ft_strnstr(const char *target, const char *src, size_t target_len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_toupper(int c);
void	ft_strfree(char **str);
int		ft_cut_to_line(char **room, char **line);
int		ft_output(char **room, char **line, int read_val);
int		get_next_line(int fd, char **line);
void	put_define(int fd);
void	put_finish(int fd);
void	put_include(int fd);
int		is_func(char *line);
void	join_dir_file(char **file, char **dir);
char	**get_c_files(void);
void	write_on_fd(int fd, char *line);
void	put_prototype(int fd);
int		is_struct(char *line);
int		put_struct(int fd);
void	put_top(int fd);

#endif
