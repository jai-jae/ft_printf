/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:59:24 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/08 17:52:05 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	ft_mul_big(t_bigint *dst, t_bigint *a, t_bigint *b)
{
	uint64_t	nbr;
	int			i;
	int			j;

	i = 0;
	while (i < a->len)
	{
		j = 0;
		while (j < b->len)
		{
			nbr = (uint64_t)a->data[i] * b->data[j];
			ft_add_smallint(dst, (uint32_t)nbr, i + j);
			ft_add_smallint(dst, (uint32_t)(nbr >> 32), i + j + 1);
			j++;
		}
		i++;
	}
}

void	ft_mul_small(t_bigint *dst, uint32_t val)
{
	uint64_t	nbr;
	uint32_t	*tmp;
	int			i;

	if (!(tmp = (uint32_t *)malloc(sizeof(uint32_t) * dst->len)))
		return ;
	ft_memcpy(tmp, dst->data, sizeof(uint32_t) * dst->len);
	ft_memset(dst->data, 0, sizeof(uint32_t) * dst->len);
	i = 0;
	while (i < dst->len)
	{
		nbr = (uint64_t)tmp[i] * val;
		ft_add_smallint(dst, (uint32_t)nbr, i);
		ft_add_smallint(dst, (uint32_t)(nbr >> 32), i + 1);
	}
	ft_memdel(&tmp);
}
