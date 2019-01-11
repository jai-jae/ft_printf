/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:03:03 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:57:14 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"

void	print_integer(t_fprec *nbr, t_pfinfo *e)
{
	int index;

	if (e->flags.prec == 0)
	{
		e->bf[nbr->dot + 1] > '4' ?
		e->bf[nbr->dot - 1] += 1 : 0;
	}
	index = 0;
	while (e->bf[index] != '.')
		index++;
	e->ret += write(e->fd, e->bf, index);
}

void	print_precision(t_fprec *nbr, t_pfinfo *e)
{
	int		len;
	int		i;
	char	*zeros;

	len = (int)ft_strlen(e->bf + nbr->dot + 1);
	if (e->flags.prec == len || e->flags.prec == len - 1)
		write(e->fd, e->bf + nbr->dot,
				e->flags.prec == len ? len + 1 : len);
	else if (e->flags.prec < len)
	{
		e->bf[nbr->dot + e->flags.prec + 1] > '4' ?
			carry_floats(nbr, e) : 0;
		e->ret += write(e->fd, e->bf + nbr->dot, e->flags.prec + 1);
	}
	else
	{
		i = e->flags.prec - len;
		e->ret += write(e->fd, e->bf + nbr->dot, len + 1);
		zeros = ft_strnew(i);
		while (i > 0)
			zeros[--i] = '0';
		write(e->fd, zeros, e->flags.prec - len);
	}
}

void	print_zerowidth_float(t_pfinfo *e)
{
	int len_inte;
	int	i;

	len_inte = 0;
	while (e->bf[len_inte] != '.')
		len_inte++;
	if (e->flags.plus == 1 || e->flags.space == 1 ||
			e->flags.neg == 1)
		len_inte += 1;
	e->flags.prec != 0 ? len_inte += 1 : 0;
	i = e->flags.width - (len_inte + e->flags.prec);
	while (i > 0)
	{
		if (e->flags.zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
		i--;
	}
}

void	print_float(t_fprec *nbr, t_pfinfo *e)
{
	nbr->sign == 1 ? check_sign_float(e) : 0;
	e->flags.prec < 0 ? e->flags.prec = 6 : 0;
	if (e->flags.minus == 1)
	{
		print_sign_float(e);
		print_integer(nbr, e);
		e->flags.prec > 0 ? print_precision(nbr, e) : 0;
		print_zerowidth_float(e);
	}
	else if (e->flags.zero == 1)
	{
		print_sign_float(e);
		print_zerowidth_float(e);
		print_integer(nbr, e);
		e->flags.prec > 0 ? print_precision(nbr, e) : 0;
	}
	else
	{
		print_zerowidth_float(e);
		print_sign_float(e);
		print_integer(nbr, e);
		e->flags.prec > 0 ? print_precision(nbr, e) : 0;
	}
	e->i++;
	free(e->bf);
}
