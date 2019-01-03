/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:25:01 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/11 14:20:04 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int k;

	i = 0;
	if (!(*to_find))
		return (char*)str;
	while (str[i])
	{
		k = 0;
		while (to_find[k] && str[i] == to_find[k])
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
