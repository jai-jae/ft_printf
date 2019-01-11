/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:20:03 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/07 00:42:42 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"
#include "libft.h"

static void		err_message(char type, t_fprec *nbr, t_pfinfo *e)
{
	if (nbr->err == ft_nan)
		e->bf = ft_strdup("nan");
	else if (nbr->err == ft_inf)
		e->bf = ft_strdup("inf");
	else if (nbr->err == ft_zero)
		e->bf = ft_strdup("0.0");
	if (type == 'F')
		ft_strupper(e->bf);
}

static void		print_width_float_error(t_pfinfo *e)
{
	int	len;
	int	i;

	if (e->flags.plus == 1 || e->flags.space == 1 ||
			e->flags.neg == 1)
		len = 4;
	else
		len = 3;
	i = e->flags.width - len;
	while (i > 0)
	{
		e->ret += write(e->fd, " ", 1);
		i--;
	}
}

void			print_float_error(char type, t_fprec *nbr, t_pfinfo *e)
{
	err_message(type, nbr, e);
	if (!(e->bf))
		return ;
	if (nbr->err == ft_zero)
		print_float(nbr, e);
	else
	{
		nbr->sign == 1 ? check_sign_float(e) : 0;
		e->flags.zero = 0;
		if (e->flags.minus == 1)
		{
			print_sign_float(e);
			e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
			print_width_float_error(e);
		}
		else
		{
			print_width_float_error(e);
			print_sign_float(e);
			e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
		}
		e->i++;
		free(e->bf);
	}
}
