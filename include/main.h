#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>
# include <ctype.h>
# include "../my_config.h"
# include "libft.h"
# include "get_next_line.h"
# include "message.h"

# define MY_STRUCT "my_struct.h"
# define TEMP_H "not_align.h"

/* put_func /_top to _finish */
void	put_top(int fd);
void	put_include(int fd);
void	put_define(int fd);
int		is_struct(char *line);
int		put_struct(int fd);
int		is_func(char *line);
void	join_dir_file(char **file, char **dir);
char	**get_c_files(void);
void	write_on_fd(int fd, char *line);
void	put_prototype(int fd);
void	put_finish(int fd);
/* do_align.c file's function */
int		need_align(char *line);
int		not_first_line(char *line);
int		find_align_point(int fd);
int		do_align(int fd, int align_point);
char 	*get_header_path(const char *name);

#endif
