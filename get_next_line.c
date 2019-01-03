#include "get_next_line.h"

int	get_next_line(const int fd, char **s)
{
	int r = 0;
	char buf[BUFF_SIZE + 1];
	static char *file;
	while ((r = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[r] = '\0';
		ft_strappend(&file, buf);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char *line;
	int fd;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
	}
	else
		printf("invalid arg\n");
	return (0);
}
