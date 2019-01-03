/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:18:50 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/16 16:46:07 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		i = ft_strncmp(s1, s2, n);
		if (i == 0)
			return (1);
	}
	return (0);
}
