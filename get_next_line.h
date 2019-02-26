/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:29:23 by thfoulon          #+#    #+#             */
/*   Updated: 2019/02/26 14:31:43 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

int		get_next_line(const int fd, char **s);

#endif
