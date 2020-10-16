#include "../Includes/main.h"
#include "../Includes/libft.h"
#include "../Includes/get_next_line.h"
#include "../Includes/my_config.h"

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
			// printf("%s\n", ent->d_name);
			if (ft_strnstr(ent->d_name, ".c", ft_strlen(ent->d_name)))
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

void	put_prototype(int fd)
{
	char	**c_files;
	// int		c_fd;

	fd = 0;
	c_files = get_c_files();
	printf("%s\n", c_files[0]);
	// while((c_fd = open()
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
	printf("%s$\n", header_path);
	fd = open(header_path, O_RDWR | O_CREAT | O_TRUNC, 0755);
	printf("%d\n", fd);


/*
** Top 부분 집어넣기
*/
	put_top(fd);
	close(fd);

/*
** Includes 부분 집어넣기
*/

/*
** Define 부분 집어넣기
*/

/*
** Prototype 부분 집어넣기
*/
	put_prototype(fd);
/*
** Endif 집어넣기
*/
	return (0);
}