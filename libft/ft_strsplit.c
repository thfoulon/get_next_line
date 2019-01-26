/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:52:45 by thfoulon          #+#    #+#             */
/*   Updated: 2018/12/10 11:58:04 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countchar(char const *s, char c)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (i > 0)
			if ((s[i] != c) && s[i])
				if (s[i - 1] == c)
					j++;
		i++;
	}
	if (s[0] != c && s[0])
		j++;
	return (j);
}

static int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

static char		*ft_addword(char const *s, char *as, int i, char c)
{
	int j;
	int y;
	int a;

	a = 0;
	y = 0;
	j = 0;
	while ((s[y] == c) && s[y])
		y++;
	while (j < i && s[y])
	{
		if (s[y] == c)
			if (s[y + 1] != c)
				j++;
		y++;
	}
	if (!(as = (char*)malloc(sizeof(char) * ft_countwords(&s[y], c))))
		return (0);
	while ((s[y] != c) && s[y])
		as[a++] = s[y++];
	as[a] = '\0';
	return (as);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**as;
	int		y;
	int		g;

	g = 0;
	y = ft_countchar(s, c);
	if (!(as = (char**)malloc(sizeof(char*) * (y + 1))))
		return (0);
	while (g < y)
	{
		as[g] = ft_addword(s, as[g], g, c);
		g++;
	}
	as[y] = 0;
	return (as);
}
