#include "../Includes/main.h"

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
