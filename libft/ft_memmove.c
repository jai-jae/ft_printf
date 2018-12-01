/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:36:35 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/25 19:34:59 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (tmp1 > tmp2)
	{
		while (len > 0)
		{
			*(tmp1 + len - 1) = *(tmp2 + len - 1);
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*tmp1++ = *tmp2++;
			len--;
		}
	}
	return (dst);
}
