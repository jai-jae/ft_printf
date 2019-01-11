/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_addition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:21:56 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/14 13:28:37 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static uint32_t		add_big(uint32_t len, uint32_t *dst, uint32_t *src)
{
	uint32_t	carry;
	uint32_t	i;

	i = 0;
	carry = 0;
	while (i < len)
	{
		dst[i] = dst[i] + src[i];
		if (carry == 1)
		{
			if (dst[i] >= src[i])
				carry = 0;
			if (dst[i] == 0xffffffff)
				carry = 1;
			dst[i]++;
		}
		else if (dst[i] < src[i])
			carry = 1;
		i++;
	}
	return (carry);
}

static uint32_t		add_small(uint32_t len, uint32_t *dst, uint32_t val)
{
	uint32_t	carry;
	uint32_t	i;

	i = 1;
	carry = 0;
	dst[0] += val;
	if (dst[0] < val)
		carry = 1;
	while (i < len)
	{
		if (carry == 1)
		{
			if (dst[i] != 0xffffffff)
				carry = 0;
			dst[i]++;
		}
		else
			break ;
	}
	return (carry);
}

void				ft_add_bigint(t_bigint *dst, t_bigint *src)
{
	if (dst->len < src->len)
		add_big(dst->len, dst->data, src->data);
	else if (add_big(src->len, dst->data, src->data))
		add_small(src->len - dst->len, dst->data, 1);
}

void				ft_add_small_pos(t_bigint *dst, uint32_t val, uint32_t pos)
{
	if (dst->len <= pos)
		return ;
	add_small(dst->len - pos, &dst->data[pos], val);
}
