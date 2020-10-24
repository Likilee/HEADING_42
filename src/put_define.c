#include "../include/main.h"

void	put_define(int fd)
{
	char	**mecro;
	char	*temp;
	int		i;
	char	*ptr;

	mecro = ft_split(MACRO, ',');
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
