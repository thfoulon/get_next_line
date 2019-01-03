/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:41:04 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/18 17:20:04 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char*)malloc(sizeof(*str) * i + 1)))
			return (0);
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
		{
			str[j] = s2[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
