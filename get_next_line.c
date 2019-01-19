/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:07:21 by thfoulon          #+#    #+#             */
/*   Updated: 2019/01/19 10:07:26 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **s)
{
	char buf[BUFF_SIZE + 1];
	static char *str;
	int	ret;
	while (ft_check(str) == 0 && )
	{
		if (*buf)
		{
			str = ft_strdup(ft_strcat(str, buf));
		}
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char *line;
	
	get_next_line(fd, &line);
	return (0);
}
