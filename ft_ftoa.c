/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:36:47 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/07 00:29:46 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "ft_printf.h"
#include "fpoint.h"

void		init_fprec(t_fprec *nbr)
{
	nbr->ext = 0;
	nbr->mantissa = 0;
	nbr->sign = 0;
	nbr->exp = 0;
	nbr->len_sosu = 0;
	nbr->diff_sosu_exp = 0;
	nbr->diff_exp_sosu = 0;
	nbr->err = -1;
	nbr->dot = 1;
}

int			process_bigint(t_fprec *nbr)
{
	if (nbr->ext == 1)
	{
		if (!(ft_create_bigint(1195, &(nbr->bg))))
			return (0);
	}
	if (nbr->ext == 0)
	{
		if (!(ft_create_bigint(79, &(nbr->bg))))
			return (0);
	}
	nbr->bg.data[0] = (uint32_t)(nbr->mantissa);
	nbr->bg.data[1] = (uint32_t)((nbr->mantissa) >> 32);
	while (!(nbr->bg.data[0] & 1))
		ft_shiftr_bigint(&nbr->bg, 1);
	return (1);
}

int			float_80(long double ld, t_fprec *nbr)
{
	uint64_t	tmp_exp;
	uint64_t	tmp_mantissa;
	int			ret;

	ret = 0;
	nbr->ext = 1;
	nbr->len_sosu = 63;
	nbr->mantissa = (*(uint64_t *)&ld);
	tmp_exp = ((uint64_t *)&ld)[1] & 0x7fff;
	nbr->exp = (int)tmp_exp - 16383;
	nbr->sign = (((uint64_t *)&ld)[1] >> 15) & 1;
	tmp_mantissa = nbr->mantissa;
	while (!(tmp_mantissa & 1) && nbr->len_sosu != 0)
	{
		nbr->len_sosu--;
		tmp_mantissa = tmp_mantissa >> 1;
	}
	if (nbr->exp == MIN_80 || nbr->exp == MAX_80)
		ret = handle_error80(nbr);
	return (ret);
}

int			float_64(double d, t_fprec *nbr)
{
	uint64_t	utemp;
	uint64_t	tmp_exp;
	uint64_t	tmp_mantissa;
	int			ret;

	ret = 0;
	nbr->len_sosu = 52;
	utemp = *(uint64_t *)&d;
	nbr->mantissa = (utemp & 0x0000fffffffffffff);
	nbr->mantissa |= 0x00010000000000000;
	tmp_exp = (utemp & 0x07ff0000000000000);
	tmp_exp = tmp_exp >> 52;
	nbr->exp = (int)tmp_exp - 1023;
	nbr->sign = (utemp >> 63) & 1;
	tmp_mantissa = nbr->mantissa;
	while (!(tmp_mantissa & 1) && nbr->len_sosu != 0)
	{
		nbr->len_sosu--;
		tmp_mantissa = tmp_mantissa >> 1;
	}
	if (nbr->exp == MIN_64 || nbr->exp == MAX_64)
		ret = handle_error64(nbr);
	return (ret);
}

char		*ft_ftoa(t_fprec *nbr)
{
	unsigned char	*bcd;
	unsigned char	*ret;

	if (!(bcd = (unsigned char *)malloc(sizeof(*bcd) * BCD_SIZE + 1)))
		return (NULL);
	if (!(process_bigint(nbr)))
		return (NULL);
	nbr->diff_sosu_exp = nbr->len_sosu - nbr->exp;
	nbr->diff_exp_sosu = nbr->exp - nbr->len_sosu;
	while (nbr->diff_sosu_exp > 0)
	{
		ft_mul_small(&(nbr->bg), 5);
		nbr->diff_sosu_exp--;
	}
	while (nbr->diff_exp_sosu > 0)
	{
		ft_shiftl_bigint(&(nbr->bg), 1);
		nbr->diff_exp_sosu--;
	}
	if ((nbr->exp == MIN_64 && (!nbr->ext)) || (nbr->exp == MIN_80 && nbr->ext))
		ft_shiftl_bigint(&(nbr->bg), 1);
	ret = double_dabble(nbr, bcd);
	ft_del_bigint(&(nbr->bg));
	free(bcd);
	return ((char *)ret);
}
