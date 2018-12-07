/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:57:02 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/07 12:11:24 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bigint.h"

typedef struct	s_bigint
{
	size_t	len;
	size_t	*nbr;
}					t_bigint;

size_t	ft_create_bigint(size_t len, t_bigint bg)
{
	bg->len = len;
	if (!(bg->nbr = (size_t *)malloc(len * sizeof(size_t))))
		return (0);
	return (len);
}

void	ft_del_bigint(t_bigint bg)
{
	bg->len = 0;
	free(bg->nbr);
}

void	ft_intval_bigint(t_bigint *dst, size_t src)
{
	dst->nbr[0] = src;
	ft_memset(&dst->nbr[1], 0, sizeof(size_t) * (dst->len - 1));
}

void	ft_bigval_bigint(t_bigint *dst, t_bigint *src);
{
	ft_memcpy(dst->nbr, src->nbr, (dst->len > src->len ?
				src->len : dst->len) * sizeof(size_t));
}

void	ft_add_bigint(size_t len, t_bigint *dst, t_bigint *src)
{
	size_t carry;
	size_t i;
	
	i = 0;
	carry = 0;
	while (i < len)
	{
		dst[i] = dst[i] + src[i];
		if (carry == 1)
		{
			if (dst[i] >= src[i]) // 자리수 유지
				carry = 0;
			if (dst[i] == UINT_MAX) //자리수 
				carry = 1;
			dst[i]++;
		}
		else
		{
			if (dst[i] < src[i]) //only happens when additional digit required
				carry = 1;
		}
		i++;
	}
	return (carry);
}
