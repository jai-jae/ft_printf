/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_process_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:23:02 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:58:29 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign_nbr(t_pfinfo *e)
{
	if (e->flags.plus || e->flags.space)
		e->ret += write(e->fd, e->flags.plus == 1 ? "+" : " ", 1);
	if (e->flags.neg == 1)
		e->ret += write(e->fd, "-", 1);
}

void	check_sign_nbr(t_pfinfo *e)
{
	char	*tmp;

	if (e->bf[0] == '-')
	{
		tmp = ft_strdup(e->bf + 1);
		free(e->bf);
		e->bf = tmp;
		e->flags.plus = 0;
		e->flags.space = 0;
		e->flags.neg = 1;
	}
}

void	process_precision_nbr(t_pfinfo *e)
{
	char	*zeros;
	char	*tmp;
	int		i;
	int		len;

	check_sign_nbr(e);
	tmp = NULL;
	if (!(e->bf))
		return ;
	len = (int)ft_strlen(e->bf);
	if (e->flags.prec == 0 && e->bf[0] == '0')
		e->bf[0] = '\0';
	else if (e->flags.prec > len)
	{
		i = e->flags.prec - len;
		if (!(zeros = ft_strnew(i)))
			return ;
		while (i > 0)
			zeros[--i] = '0';
		tmp = ft_strjoin(zeros, e->bf);
		free(zeros);
		free(e->bf);
		e->bf = tmp;
	}
	e->flags.prec >= 0 ? e->flags.zero = 0 : 0;
}

void	print_zerowidth_nbr(t_pfinfo *e)
{
	int len;
	int i;

	if (e->flags.plus == 1 || e->flags.space == 1 ||
			e->flags.neg == 1)
		len = (int)ft_strlen(e->bf) + 1;
	else
		len = (int)ft_strlen(e->bf);
	i = e->flags.width - ((e->flags.prec > (int)ft_strlen(e->bf)
				? e->flags.prec : 0) + len);
	while (i > 0)
	{
		if (e->flags.zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
		i--;
	}
}

void	print_nbr(t_pfinfo *e)
{
	process_precision_nbr(e);
	if (e->flags.minus == 1)
	{
		print_sign_nbr(e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
		print_zerowidth_nbr(e);
	}
	else if (e->flags.zero == 1)
	{
		print_sign_nbr(e);
		print_zerowidth_nbr(e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	else
	{
		print_zerowidth_nbr(e);
		print_sign_nbr(e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	e->i++;
	free(e->bf);
}
