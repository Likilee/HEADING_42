#include "../Includes/main.h"

void	put_finish(int fd)
{
	write(fd, "#endif\n", 7);
}