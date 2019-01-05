#include "get_next_line.h"

int	get_next_line(const int fd, char **s)
{
	int r = 0;
	char buf[BUFF_SIZE + 1];
	static t_list *lst;
	if (!s || fd < 1)  //cas erreur
		return (-1);
	ft_lstnew(); //creation lst
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)  // stockage fichier dans list
	{
		buf[r] = '\0';
		ft_strappend((*lst)->content, buf);
	}
	ft_strtok();  //decoupe du fichier
	if ( '\n' )
		return (1);	//termine fonction
	if ( '\0' )  
		return (0);
}

int	main(int ac, char **av)
{
	char *line;
	int fd;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("open(); error\n");
			return (1);
		}
		get_next_line(fd, &line)
		printf("%s\n"', line);
	}
	return (0);
}
