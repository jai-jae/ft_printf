/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:10 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/24 21:25:20 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + 1;
	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_min(n + 1, len))))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
