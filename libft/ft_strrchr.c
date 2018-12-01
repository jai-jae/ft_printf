/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:27:48 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/10 21:35:12 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	i = ft_strlen(s);
	tmp = (char *)s;
	if ((char)c == '\0')
		return (tmp + i);
	while ((int)i >= 0)
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
