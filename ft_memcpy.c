/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:19:34 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/24 18:27:24 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	if (n == 0)
		return (tmp1);
	while (n > 0)
	{
		*tmp1++ = *tmp2++;
		n--;
	}
	return (dst);
}
