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

int		ft_next_line(char **s, char **line, int r, int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		str = ft_strdup(s[fd] + i + 1);
		ft_strdel(&s[fd]);
		s[fd] = str;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		ft_strdel(&s[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!(s[fd]))
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buff);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_next_line(s, line, r, fd));
}
