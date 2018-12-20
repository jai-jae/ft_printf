/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 23:08:10 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 11:49:06 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "fpoint.h"

int		handle_error64(t_fprec *nbr)
{
	if (nbr->exp == MIN_64 && nbr->len_sosu == 0)
	{
		nbr->err = zero;
		return (0);
	}
	else if (nbr->exp == MIN_64 && nbr->len_sosu != 0)
	{
		nbr->mantissa &= 0x0000fffffffffffff;
		return (0);
	}
	else if (nbr->exp == MAX_64 && nbr->len_sosu == 0)
	{
		nbr->err = inf;
		return (1);
	}
	else if (nbr->exp == MAX_64 && nbr->len_sosu != 0)
	{
		nbr->err = nan;
		return (1);
	}
	return (-1);
}

int		handle_error80(t_fprec *nbr)
{
	if (nbr->exp == MIN_80 && nbr->len_sosu == 0)
	{
		nbr->err = zero;
		return (1);
	}
	else if (nbr->exp == MIN_80 && nbr->len_sosu != 0)
		return (0);
	else if ((nbr->exp == MAX_80 && nbr->len_sosu == 0))
	{
		nbr->err = INF;
		return (1);
	}
	else if (nbr->exp == MAX_80 && nbr->len_sosu != 0)
	{
		nbr->err = NAN;
		return (1);
	}
	return (-1);
}
