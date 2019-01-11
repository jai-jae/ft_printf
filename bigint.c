/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:28:29 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/17 12:25:31 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

uint32_t	ft_create_bigint(uint32_t len, t_bigint *bg)
{
	bg->len = len;
	if (!(bg->data = (uint32_t *)malloc(sizeof(uint32_t) * len)))
		return (0);
	ft_memset(bg->data, 0, sizeof(uint32_t) * (bg->len));
	return (len);
}

void		ft_del_bigint(t_bigint *bg)
{
	bg->len = 0;
	free(bg->data);
}

void		ft_initsmall_bigint(t_bigint *dst, uint32_t val)
{
	dst->data[0] = val;
	ft_memset(&dst->data[1], 0, sizeof(uint32_t) * (dst->len - 1));
}

void		ft_bigval_bigint(t_bigint *dst, t_bigint *src)
{
	ft_memcpy(dst->data, src->data, (dst->len > src->len ?
				src->len : dst->len) * sizeof(uint32_t));
}
