#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

int	get_next_line(const int fd, char **s);

typedef struct	s_list
{
	int	fd;
	void	*content;
	struct s_list	*next;
}		t_list;

#endif
