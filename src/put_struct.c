#include "../include/main.h"

/*
** is_struct :
** 현재 읽어온 한 줄이 구조체 관련 줄인지 여부를 확인 /
** step1. 문자열에 '#' , '/' 가 있으면 주석줄
** step2. 문자열에 알파벳이 있으면 구조체 관련줄
** step3. 문자열에 중괄호가 있으면 구조체 관련줄
*/
int		is_struct(char *line)
{
	if (ft_strnstr(line, "/*", 2) || ft_strnstr(line, "*/", 2) || ft_strnstr(line, "**", 2))
			return (0);
	while (*line)
	{
		if (ft_isalpha(*line))
			return (1);
		if (*line == '{' || *line == '}')
			return (1);
		++line;
	}
	return (0);
}

int	put_struct(int fd)
{
	int		config_fd;
	int		gnl_val;
	char	*line;
	int		yes_struct;

	yes_struct = 0;
	if((config_fd = open(MY_STRUCT, O_RDONLY)) < 0)
	{
		printf("%s", ERR_MY_STRUCT);
		return (0);
	}
	gnl_val = 1;
	while (gnl_val > 0)
	{
		gnl_val = get_next_line(config_fd, &line);
		if (is_struct(line))
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			if (ft_strchr(line, '}') && *(ft_strchr(line, '}') + 1) != ';')
				write(fd, "\n", 1);
			yes_struct = 1;
		}
		free(line);
	}
	close(config_fd);
	return (yes_struct);
}