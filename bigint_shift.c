/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:30:34 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/19 19:35:45 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void	ft_shiftr_bigint(t_bigint *dst, uint32_t val)
{
	uint32_t	i;
	uint32_t	len;

	len = dst->len;
	i = 1;
	dst->data[0] = dst->data[0] >> val;
	while (i < dst->len)
	{
		dst->data[i - 1] |= dst->data[i] << (32 - val);
		dst->data[i] = dst->data[i] >> val;
		i++;
	}
}

void	ft_shiftl_bigint(t_bigint *dst, uint32_t val)
{
	int	i;

	i = dst->len - 1;
	dst->data[i] = dst->data[i] << val;
	i--;
	while (i >= 0)
	{
		dst->data[i + 1] |= dst->data[i] >> (32 - val);
		dst->data[i] = dst->data[i] << val;
		i--;
	}
}
