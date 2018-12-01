/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:44:17 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/24 18:29:18 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t strldst;
	size_t strlsrc;
	size_t i;

	strldst = ft_strlen(dst);
	strlsrc = ft_strlen(src);
	i = 0;
	if (strldst >= size)
		return (size + strlsrc);
	while (src[i] != '\0' && i < size - strldst - 1)
	{
		dst[strldst + i] = src[i];
		i++;
	}
	dst[strldst + i] = '\0';
	return (strldst + strlsrc);
}
