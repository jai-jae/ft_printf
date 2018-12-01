/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:41:04 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/08 17:46:18 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;
	size_t	cnt;

	tmp1 = (char *)haystack;
	tmp2 = (char *)needle;
	if (ft_strlen(tmp2) == 0)
		return (tmp1);
	i = 0;
	cnt = 0;
	while (tmp1[i])
	{
		while (tmp1[i + cnt] == tmp2[cnt])
		{
			cnt++;
			if (cnt == ft_strlen(tmp2))
				return (&tmp1[i]);
		}
		cnt = 0;
		i++;
	}
	return (NULL);
}
