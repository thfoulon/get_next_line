#include "get_next_line.h"

int	get_next_line(int fd, char **s)
{
	static char ret[BUFF_SIZE + 1];
	read(fd, ret, BUFF_SIZE);
}

int	main()
{
	int fd;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, ret);
	return (0);
}
