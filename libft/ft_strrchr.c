/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:17:33 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/17 16:15:27 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s1;

	s1 = (char*)s;
	len = ft_strlen(s1);
	while (s[len] != c && len > 0)
		len--;
	if (s[len] == c)
		return (char*)&s[len];
	return (NULL);
}
