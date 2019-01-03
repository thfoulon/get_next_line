/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:41:27 by thfoulon          #+#    #+#             */
/*   Updated: 2018/12/03 16:11:21 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*s1;

	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (n--)
	{
		if (*s1 != c1)
			s1++;
		else
			return (void*)s1;
	}
	return (0);
}
