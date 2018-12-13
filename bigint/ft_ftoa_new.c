/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:36:47 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/14 00:10:54 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "bigint.h"

void		init_fprec(t_fprec *nbr)
{
	nbr->mantissa = 0;
	nbr->sign = 0;
	nbr->exp = 0;
	nbr->len_sosu = 0;
}

void		process_bigint(t_fprec *nbr)
{
	int			tmp_exp;

	tmp_exp = nbr->exp;
	ft_create_bigint(7 + ft_abs(nbr->exp), &(nbr->bg));
	nbr->bg.data[0] = (uint32_t)(nbr->mantissa);
	nbr->bg.data[1] = (uint32_t)((nbr->mantissa) >> 32);
	while (!(nbr->bg.data[0] & 1))
		ft_shiftr_bigint(&nbr->bg, 1);
}

void		init_mantissa64(double d, t_fprec *nbr)
{
	uint64_t	utemp;
	uint64_t	tmp_exp;
	uint64_t	tmp_mantissa;

	nbr->len_sosu = 52;
	utemp = *(uint64_t *)&d;
	nbr->mantissa |= (utemp & 0x0000fffffffffffff);
	nbr->mantissa |= 0x00010000000000000;
	tmp_exp |= (utemp & 0x07ff0000000000000);
	tmp_exp = tmp_exp >> 52;
	nbr->exp = (int)tmp_exp - 1023;
	nbr->sign = (utemp >> 63) & 1;
	tmp_mantissa = nbr->mantissa;
	while (!(tmp_mantissa & 1))
	{
		nbr->len_sosu--;
		tmp_mantissa = tmp_mantissa >> 1;
	}
}

int         ft_ftoa64(double d)
{
	t_fprec			nbr;
//	uint64_t		utemp;
//	uint64_t		tmp_exp;
//	uint64_t		tmp_mantissa;
	int 			diff_exp_sosu;
	int				diff_sosu_exp;

	init_fprec(&nbr);
/*	nbr.len_sosu = 52;
	utemp = *(uint64_t *)&d; //TODO 80bit needs to increment pointer
	nbr.mantissa |= (utemp & 0x0000fffffffffffff);
	nbr.mantissa |= 0x00010000000000000; //include implicit 1
	tmp_mantissa = nbr.mantissa;
	tmp_exp |= (utemp & 0x07ff0000000000000);
	tmp_exp = tmp_exp >> 52;
	while (!(tmp_mantissa & 1))
	{
		nbr.len_sosu--;
		tmp_mantissa = tmp_mantissa >> 1;
	}
	nbr.exp = (int)tmp_exp - 1023;
	nbr.sign |= (utemp >> 63) & 1; */
	init_mantissa64(d, &nbr);
	process_bigint(&nbr);


	diff_exp_sosu = nbr.exp - nbr.len_sosu;
	diff_sosu_exp = nbr.len_sosu - nbr.exp;
	while (diff_sosu_exp > 0)
	{
		ft_mul_small(&(nbr.bg), 5);
		diff_sosu_exp--;
	}
	while (diff_exp_sosu > 0)
	{
		ft_shiftl_bigint(&(nbr.bg), 1);
		diff_exp_sosu--;
	}
	//TODO  print_bigint(&nbr);
	printf("data[0] : %u\n", nbr.bg.data[0]);
	printf("data[1] : %u\n", nbr.bg.data[1]);
	return (1);
}

int main()
{
	int a;
	double b = 110.0625 ;
	a = ft_ftoa64(b);
	return (0);
}
