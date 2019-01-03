/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:48:31 by thfoulon          #+#    #+#             */
/*   Updated: 2018/12/03 19:59:12 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	char	*cpy;

	start = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == len + 1)
		return (ft_strdup(""));
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len = len - start + 1;
	if (!(cpy = ft_strsub(s, start, len)))
		return (NULL);
	return (cpy);
}
