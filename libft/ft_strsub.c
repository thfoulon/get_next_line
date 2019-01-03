/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:22:26 by thfoulon          #+#    #+#             */
/*   Updated: 2018/12/02 18:43:55 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(s1 = (char*)malloc(sizeof(*s1) * len + 1)))
			return (0);
		len = start + len;
		while (start < len)
		{
			s1[i] = s[start];
			start++;
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (0);
}
