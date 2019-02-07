/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:26:59 by thfoulon          #+#    #+#             */
/*   Updated: 2019/01/26 15:18:26 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_next_line(char *s, char **line, int r, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		*line = ft_strsub(s, 0, i);
		tmp = ft_strdup(s + i + 1);
		ft_strdel(&s);
		s = ft_strdup(tmp);
		if (s[0] == '\0')
			ft_strdel(&s);
	}
	else if (s[i] == '\0')
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s);
		ft_strdel(&s);
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!(s))
			s = ft_strnew(1);
		tmp = ft_strjoin(s, buff);
		ft_strdel(&s);
		s = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && (s == NULL || s[0] == '\0'))
		return (0);
	return (ft_next_line(s, line, r, fd));
}

int		main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		r;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			printf("open(); error\n");
			return (1);
		}
		while ((r = get_next_line(fd, &s)) > 0)
			printf("%d, %s\n", r, s);
		printf("%d, %s\n", r, s);
	}
	else
		printf("arg error\n");
	return (0);
}
