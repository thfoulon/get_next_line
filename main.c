#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		r;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((r = get_next_line(fd, &s)) > 0)
			printf("%d, %s\n", r, s);
		printf("%d, %s\n", r, s);
		close(fd);
	}
	else
		printf("open(); error\n");
	return (0);
}
