/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:29:22 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/16 16:44:20 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	i = 0;
	if (s && f)
	{
		if (!(s1 = ft_strdup(s)))
			return (0);
		while (s[i])
		{
			s1[i] = f(i, s[i]);
			i++;
		}
		return (s1);
	}
	return (0);
}
