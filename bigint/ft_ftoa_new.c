/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:36:47 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/16 17:13:16 by jaelee           ###   ########.fr       */
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
	ft_memset(nbr->bcd, 0, BCD_SIZE);
}

void		print_signed_zero(t_fprec *nbr)
{
	ft_putstr("signed zero");
}

void		print_inf()
{
	ft_putstr("inf\n");
}

void		print_nan()
{
	ft_putstr("nan\n");
}

void		process_bigint(t_fprec *nbr)
{
	int			tmp_exp;

	tmp_exp = nbr->exp;
	ft_create_bigint(90, &(nbr->bg)); //TODO FREEEEEEEE!!!!!
	nbr->bg.data[0] = (uint32_t)(nbr->mantissa);
	nbr->bg.data[1] = (uint32_t)((nbr->mantissa) >> 32);
	while (!(nbr->bg.data[0] & 1))
		ft_shiftr_bigint(&nbr->bg, 1);
}

int		handle_strange(t_fprec *nbr)
{
	if (nbr->exp == -1023 && nbr->len_sosu == 0)
	{
		print_signed_zero(nbr);
		return (0);
	}
	else if (nbr->exp == -1023 && nbr->len_sosu != 0)
	{
		nbr->mantissa &= 0x0000fffffffffffff;
		return (1);
	}
	else if (nbr->exp == 1024 && nbr->len_sosu == 0)
	{
		print_inf();
		return (0);
	}
	else if (nbr->exp == 1024 && nbr->len_sosu != 0)
	{
		print_nan();
		return (0);
	}
	return (-1);
}

int		init_mantissa64(double d, t_fprec *nbr)
{
	uint64_t	utemp;
	uint64_t	tmp_exp;
	uint64_t	tmp_mantissa;
	int			ret;

	ret = 1;
	nbr->len_sosu = 52;
	utemp = *(uint64_t *)&d;
	nbr->mantissa = (utemp & 0x0000fffffffffffff);
	nbr->mantissa |= 0x00010000000000000;
	tmp_exp = (utemp & 0x07ff0000000000000);
	tmp_exp = tmp_exp >> 52;
	nbr->exp = (int)tmp_exp - 1023;
	nbr->sign = (utemp >> 63) & 1;
	tmp_mantissa = nbr->mantissa;
	while (!(tmp_mantissa & 1))
	{
		nbr->len_sosu--;
		tmp_mantissa = tmp_mantissa >> 1;
	}
	if (nbr->exp == -1023 || nbr->exp == 1024)
		ret = handle_strange(nbr);
	return (ret);
}

int         ft_ftoa(double d)
{
	t_fprec			nbr;
	int				diff_exp_sosu;
	int				diff_sosu_exp;
	int				strange;

	init_fprec(&nbr);
	strange = init_mantissa64(d, &nbr);
	if (strange == 1)
	{
		process_bigint(&nbr);
		diff_sosu_exp = nbr.len_sosu - nbr.exp;
		diff_exp_sosu = nbr.exp - nbr.len_sosu;
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
		if (nbr.exp == -1023)
			ft_shiftl_bigint(&(nbr.bg), 1);
		printf("exp : %d\n", nbr.exp);
		printf("sosu: %d\n", nbr.len_sosu);
		for (int j=0; j < 3; j++)
			printf("data[%d] : %u\n", j, nbr.bg.data[j]);
		double_dabble(&nbr);
	}
	return (1);
}

int main()
{
	int a;
	double b;
	b = 1.0e-323;
	a = ft_ftoa(b);
	return (0);
}
