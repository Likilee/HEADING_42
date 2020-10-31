#include "../include/main.h"

int		need_align(char *line)
{
	if (ft_strchr(line, '#') || *line == '/' || *line == '*')
		return (0);
	while (*line)
	{
		if(ft_isalpha(*line))
		{
			while (ft_isalpha(*line))
				++line;
			if (*line != '\0')
				return (1);
			else
				return (0);
		}
		++line;
	}
	return (0);
}

int		not_first_line(char *line)
{
	if ((ft_strchr(line, ')') && !(ft_strchr(line, '(')))
		|| (ft_strchr(line, ',') && !(ft_strchr(line, '(')) && !(ft_strchr(line, ')'))))
		return (1);
	return (0);
}

int		find_align_point(int fd)
{
	int		gnl_val;
	char	*line;
	int		point;
	int		max_point;
	int		len;

	gnl_val = 1;
	max_point = 0;
	while (gnl_val > 0)
	{
		point = 0;
		len = 0;
		gnl_val = get_next_line(fd, &line);
		if (need_align(line))
		{
			while (isspace(line[point]))
			{
				if(line[point] == '\t')
				{
					len += 4 - len % 4;
				}
				else
					++len;
				++point;
			}
			while (line[point] && line[point++] != '\t')
				++len;
			if (not_first_line(line))
				len = 0;
			if (len > max_point)
				max_point = len;
		}
		free(line);
	}
	max_point += 4 - (max_point + 1) % 4;
	return (max_point);
}

int		do_align(int fd, int align_point)
{
	int		gnl_val;
	char	*line;
	char	*temp;
	int		point;
	int		len;
	int		itr;
	int		new_fd;

	new_fd = open(get_header_path(HEADER_NAME), O_RDWR | O_CREAT | O_TRUNC, 0755);
	gnl_val = 1;
	while (gnl_val > 0)
	{
		point = 0;
		len = 0;
		gnl_val = get_next_line(fd, &line);
		if (need_align(line))
		{
			if (not_first_line(line))
			{
				while (isspace(line[point]))
					++point;
				len = strlen(&line[point]);
				itr = align_point / 4 + 4;
				if(!(temp = (char *)calloc(sizeof(char), len + itr + 1)))
					return (0);
				while(itr--)
					strcat(temp, "\t");
				strcat(temp, &line[point]);
			}
			else
			{
				while (isspace(line[point]))
				{
					if(line[point] == '\t')
						len += 4 - point % 4;
					else
						++len;
					++point;
				}
				if (!strchr(&line[point], '\t'))
				{
					printf("\n%s", NO_TAB);
					printf("Problem in this line : %s\n", line);
					printf("Check 'not_align.h'\n");
					printf("***************************************************\n\n");

					return (0);
				}
				while (line[point] && line[point++] != '\t' )
					++len;
				itr = (align_point - len) / 4 + 1;
				if(!(temp = (char *)calloc(sizeof(char), ft_strlen(line) + itr + 3)))
					return (0);
				ft_strlcpy(temp, line, point);
				while (itr--)
					strcat(temp, "\t");
				while (isspace(line[point]))
					++point;
				strcat(temp, &line[point]);
			}
			write(new_fd, temp, ft_strlen(temp));
			write(new_fd, "\n", 1);
			free(temp);
		}
		else
		{
			write(new_fd, line, ft_strlen(line));
			write(new_fd, "\n", 1);
		}
		free(line);
	}
	close (new_fd);
	return (1);
}
