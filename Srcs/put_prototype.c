#include "../Includes/main.h"

/*
** 현재 읽어온 한 줄이 함수 선언부인지 여부를 확인 /
** step1. 시작 문자가 들여쓰기이면 out/ 시작문자가 알파벳이 아니면 out
** step2. 문자열에 '(' 가 없으면 out
*/
int		is_func(char *line)
{
	if (isspace(*line) || !ft_isalpha(*line) || ft_strnstr(line, "static", strlen(line)))
		return (0);
	else if (ft_strchr(line, '('))
		return (1);
	return (0);
}

/*
** join_slash + SRC_DIR에 / 붙여주는거.
*/
void	join_dir_file(char **file, char **dir)
{
	char *temp;

	temp = *file;
	*file = ft_strjoin("/", *file);
	free(temp);
	temp = *file;
	*file = ft_strjoin(*dir, *file);
	free (temp);
}

/*
** SRC_DIR에서 C파일만 골라서 경로 text를 배열에 저장
*/
char	**get_c_files(void)
{
    DIR				*dir;
    struct dirent	*ent;
	char			**c_files;
	char			*dirname;
	int				num;

	if(!(c_files = (char **)malloc(sizeof(char *) * MAX_SOURCE_FILE)))
		return (NULL);
    dir = opendir(SRC_DIR);
	dirname = SRC_DIR;
    if (dir != NULL)
	{
		num = 0;
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL)
		{
			if (ft_strnstr(ent->d_name, ".c", ft_strlen(ent->d_name))
				&& !ft_strnstr(ent->d_name, "main", ft_strlen(ent->d_name)))
			{
				c_files[num] = ft_strdup(ent->d_name);
				join_dir_file(&c_files[num], &dirname);
				++num;
			}

		}
		c_files[num] = NULL;
		closedir(dir);
    }
	else
	{
        /* could not open directory */
        perror ("");
        return (NULL);
    }
	return (c_files);
}

/*
** 내 헤더에 함수 프로토타입을 write 한다.
*/
void	write_on_fd(int fd, char *line)
{
	int len;

	len = ft_strlen(line);
	write(fd, line, len);
	if (line[len - 1] == ')')
		write(fd, ";", 1);
	write(fd, "\n", 1);
}

/*
** 파일을 순차적으로 열어서 함수선언부를 가져온다
*/
void	put_prototype(int fd)
{
	char	**c_files;
	int		c_fd;
	int		i;
	char	*line;
	int		gnl_val;

	c_files = get_c_files();
	if (c_files[0] == NULL)
		printf("%s\n", NO_C_FILES);
	i = 0;
	gnl_val = 1;
	while((c_fd = open(c_files[i], O_RDONLY)) > 0)
	{
		while (gnl_val > 0)
		{
			gnl_val = get_next_line(c_fd, &line);
			if (is_func(line))
			{
				write_on_fd(fd, line);
				while (ft_strchr(line, ')') == NULL)
				{
					free(line);
					gnl_val = get_next_line(c_fd, &line);
					write_on_fd(fd, line);
				}
			}
			free(line);
		}
		++i;
		close(c_fd);
		gnl_val = 1;
	}
	write(fd, "\n", 1);
}