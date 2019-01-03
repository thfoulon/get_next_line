/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:49:42 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/16 14:06:37 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;
	size_t			i;

	i = 0;
	sa = (unsigned char*)s1;
	sb = (unsigned char*)s2;
	while (i < n)
	{
		if (sa[i] != sb[i])
			return (int)sa[i] - (int)sb[i];
		i++;
	}
	return (0);
}
