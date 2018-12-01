/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:47:16 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/24 18:30:59 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = ft_strsub(s1, 0, len + 1)))
		return (NULL);
	if (!(ptr))
		return (NULL);
	while (i < len && s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
