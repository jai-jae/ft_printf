/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:24:17 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/10 19:17:35 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
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
	while (tmp1[i] != '\0' && i < n)
	{
		while (tmp1[i + cnt] == tmp2[cnt] && (i + cnt) < n)
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
