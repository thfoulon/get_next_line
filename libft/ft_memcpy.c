/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:34:07 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/14 14:49:36 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*cpy;

	str = (char*)src;
	cpy = (char*)dst;
	i = 0;
	while (i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (dst);
}
