/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:49:45 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/23 15:24:55 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_count(int n)
{
	int				i;
	int				v;
	unsigned int	nb;
	char			*tab;

	v = 1;
	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	nb = n;
	while (nb / v >= 10)
	{
		v = v * 10;
		i++;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * i + 1)))
		return (0);
	return (tab);
}

char			*ft_itoa(int n)
{
	int				v;
	unsigned int	nb;
	int				i;
	char			*tab;

	if (!(tab = ft_count(n)))
		return (0);
	v = 1;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb / v >= 10)
		v = v * 10;
	i = 0;
	if (n < 0)
		tab[i++] = '-';
	while (v >= 1)
	{
		tab[i++] = (nb / v) + '0';
		nb = nb % v;
		v = v / 10;
	}
	tab[i] = '\0';
	return (tab);
}
