#include "../include/main.h"

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