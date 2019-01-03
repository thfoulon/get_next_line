/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:21:44 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/16 16:43:26 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(s1 = ft_strdup(s)))
			return (0);
		while (s[i])
		{
			s1[i] = f(s[i]);
			i++;
		}
		return (s1);
	}
	return (0);
}
