/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:27:10 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/13 17:42:25 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!(*to_find))
		return (char*)str;
	while (str[i] && i < len)
	{
		k = 0;
		while (to_find[k] && str[i] == to_find[k] && i < len)
		{
			if (to_find[k + 1] == '\0')
				return (char*)str + (i - k);
			i++;
			k++;
		}
		i = i - k;
		i++;
	}
	return (0);
}
