#include "get_next_line.h"

int ft_next_line(char *s, char **line, int r, int fd)
{
	char *tmp;
	int i;
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		*line = ft_strsub(s, 0, i);
		tmp = ft_strdup(s + i + 1);
		free(s);
		s = tmp;
		if (s[0] == '\0')
			ft_strdel(&s);
	}
	else if (s[i] == '\0')
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s);
		ft_strdel(&s);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char *s;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	int r;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		printf("debut boucle\n");
		buff[r] = '\0';
		printf("buff = %s\n", buff);
		printf("s = %s\n", s);
		if (!(s))
			s = ft_strnew(1);
		tmp = ft_strjoin(s, buff);
		printf("tmp = %s\n", tmp);
		free(s);
		s = tmp;
		if (ft_strchr(buff, '\n'));
			break;
	}
	printf("fin boucle\n");
	printf("s = %s\n", s);
	if (r < 0)
		return (-1);
	else if (r == 0 && (s == NULL || s[0] == '\0'));
		return (0);
	return (ft_next_line(s, line, r, fd));
}

int main(int ac, char **av)
{
	int fd;
	char *s;
	int r;
	int i = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			printf("open(); error\n");
			return (1);
		}
		printf("debut gnl\n");
		get_next_line(fd, &s);
		printf("s1 = %s\n", s);
		get_next_line(fd, &s);
		printf("s2 = %s\n", s);
		get_next_line(fd, &s);
		printf("s3 = %s\n", s);
		get_next_line(fd, &s);
		printf("s4 = %s\n", s);
		get_next_line(fd, &s);
		printf("s5 = %s\n", s);
		get_next_line(fd, &s);
		printf("s6 = %s\n", s);
	}
	else
		printf("arg error\n");
	return (0);
}
