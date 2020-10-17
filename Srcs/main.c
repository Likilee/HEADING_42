#include "../Includes/main.h"
#include "../Includes/libft.h"
#include "../Includes/get_next_line.h"
#include "../my_config.h"

void		put_top(int fd)
{
	char 		*header_upper;
	int			len;
	int			i;

	header_upper = ft_strdup(HEADER_NAME);
	len = ft_strlen(HEADER_NAME);
	i = 0;
	while (i < len)
	{
		header_upper[i] = ft_toupper(header_upper[i]);
		if (header_upper[i] == '.')
			header_upper[i] = '_';
		++i;
	}
	write(fd, "#ifndef ", 8);
	write(fd, header_upper, len);
	write(fd, "\n", 1);
	write(fd, "# define ", 9);
	write(fd, header_upper, len);
	write(fd, "\n\n", 2);
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

	if(!(c_files = (char **)malloc(sizeof(char *) * 200)))
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
				// printf("%s\n", ent->d_name);
				c_files[num] = ft_strdup(ent->d_name);
				join_dir_file(&c_files[num], &dirname);
				// printf("%s\n", c_files[num]);
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
** 현재 읽어온 한 줄이 함수 선언부인지 여부를 확인 /
** step1. 시작 문자가 들여쓰기이면 out/ 시작문자가 알파벳이 아니면 out
** step2. 문자열에 '(' 가 없으면 out
*/
int		is_func(char *line)
{
	if (isspace(*line) || !ft_isalpha(*line))
		return (0);
	else if (ft_strchr(line, '('))
		return (1);
	return (0);
}

/*
** 현재 읽어온 한 줄이 함수 선언부인지 여부를 확인 /
** step1. 시작 문자가 들여쓰기이면 out/ 시작문자가 알파벳이 아니면 out
** step2. 문자열에 '(' 가 없으면 out
*/
int		is_struct(char *line)
{
	if (ft_strchr(line, '#'))
			return (0);
	return (1);
}
/*
** 내 헤더에 함수 프로토타입을 추가한다.
*/
void	write_on_fd(int fd, char *line)
{
	write(fd, line, ft_strlen(line));
	write(fd, ";\n", 2);
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

	i = 0;
	gnl_val = 1;
	while((c_fd = open(c_files[i], O_RDONLY)) > 0)
	{
		// printf("%s\n", c_files[i]);
		// printf("------\n");
		while (gnl_val > 0)
		{
			gnl_val = get_next_line(c_fd, &line);
			if (is_func(line))
			{
				// printf("%s\n", line);
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
		// printf("------\n");
	}
	write(fd, "\n", 1);
}

void	put_finish(int fd)
{
	write(fd, "#endif\n", 7);
}

void	put_include(int fd)
{
	char	**library;
	int		i;

	library = ft_split(LIB, ' ');
	i = 0;
	while (library[i])
	{
		write(fd, "# include ", 10);
		write(fd, library[i], ft_strlen(library[i]));
		write(fd, "\n", 1);
		++i;
	}
	write (fd, "\n", 1);
	ft_arr_free (library);
}

void	put_struct(int fd)
{
	int		config_fd;
	int		gnl_val;
	char	*line;

	if((config_fd = open(MY_STRUCT, O_RDONLY)) < 0)
	{
		printf("%s", ERR_MY_STRUCT);
		return ;
	}
	gnl_val = 1;
	while (gnl_val > 0)
	{
		gnl_val = get_next_line(config_fd, &line);
		if (is_struct(line))
		{
			// printf("%s\n", line);
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		free(line);
	}
}

void	put_define(int fd)
{
	char	**mecro;
	char	*temp;
	int		i;
	char	*ptr;

	mecro = ft_split(MECRO, ',');
	i = 0;
	while (mecro[i])
	{
		temp = mecro[i];
		mecro[i] = ft_strtrim(mecro[i], " ");
		free (temp);
		write(fd, "# ifndef ", 9);
		ptr = ft_strchr(mecro[i], ' ');
		write(fd, mecro[i], ptr - mecro[i]);
		write(fd, "\n#  define ", 11);
		write(fd, mecro[i], ft_strlen(mecro[i]));
		write(fd, "\n# endif\n\n", 10);
		++i;
	}
}


int		main(void)
{
	int		fd;
	char	*header_path;
	char	*temp;

/*
** 헤더파일 생성 및 파일 열기
*/
	header_path = ft_strjoin(INCLUDE_DIR, "/");
	temp = header_path;
	header_path = ft_strjoin(header_path, HEADER_NAME);
	free(temp);
	fd = open(header_path, O_RDWR | O_CREAT | O_TRUNC, 0755);
/*
** Top 부분 집어넣기
*/
	put_top(fd);
/*
** Includes 부분 집어넣기
*/
	put_include(fd);
/*
** Define 부분 집어넣기
*/
	put_define(fd);
/*
** Struct 부분 집어넣기
*/
	put_struct(fd);
/*
** Prototype 부분 집어넣기
*/
	put_prototype(fd);
/*
** Endif 집어넣기
*/
	put_finish(fd);
	close(fd);
	printf("Your header Made!: %s$\n", header_path);
	return (0);
}
