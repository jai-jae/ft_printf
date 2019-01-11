/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_dabble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:48:42 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/22 08:23:21 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "ft_printf.h"
#include "fpoint.h"

static int			first_index_bigint(t_fprec *nbr)
{
	int	i;

	i = (int)(nbr->bg.len) - 1;
	while (i >= 0)
	{
		if (nbr->bg.data[i] != 0)
			return (i);
		i--;
	}
	return (0);
}

static int			size_checker(t_fprec *nbr, int src_size)
{
	int			ret;
	uint32_t	val;

	ret = 0;
	val = nbr->bg.data[src_size];
	while (val != 0)
	{
		val = val >> 1;
		ret++;
	}
	return (ret);
}

static void			shift_bcd(unsigned char *bcd, int index_bcd)
{
	int	i;

	i = index_bcd;
	bcd[i] = bcd[i] << 1;
	while (i < BCD_SIZE - 1)
	{
		bcd[i] |= bcd[i + 1] >> 7;
		bcd[i + 1] = bcd[i + 1] << 1;
		i++;
	}
}

static void			check_carry(unsigned char *bcd, int *shift_pos, int b_size)
{
	int tmp_pos;

	tmp_pos = *shift_pos;
	while (tmp_pos < BCD_SIZE)
	{
		if (bcd[tmp_pos] >= 5 && b_size > 0)
		{
			bcd[tmp_pos] += 123;
			tmp_pos == *shift_pos ? *shift_pos = (*shift_pos) - 1 : 0;
		}
		tmp_pos++;
	}
}

unsigned char		*double_dabble(t_fprec *nbr, unsigned char *bcd)
{
	int					src_size;
	uint32_t			cmp;
	int					b_size;
	int					shift_pos;

	shift_pos = BCD_SIZE - 1;
	ft_memset(bcd, 0, BCD_SIZE + 1);
	src_size = first_index_bigint(nbr);
	b_size = size_checker(nbr, src_size);
	cmp = (0x80000000 >> (32 - b_size));
	b_size += (src_size * 32);
	while (src_size >= 0)
	{
		while (cmp > 0)
		{
			b_size--;
			bcd[BCD_SIZE - 1] += (!!(cmp & nbr->bg.data[src_size]));
			check_carry(bcd, &shift_pos, b_size);
			cmp = cmp >> 1;
			b_size > 0 ? shift_bcd(bcd, shift_pos) : 0;
		}
		cmp = 0x80000000;
		src_size--;
	}
	return (process_output(nbr, &bcd[shift_pos], BCD_SIZE - shift_pos));
}
