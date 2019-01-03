#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

int	get_next_line(const int fd, char **s);

struct	s_type {
	void	*content;
	int	size;
}	t_point;

#endif
