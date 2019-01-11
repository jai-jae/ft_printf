/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_process_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:23:02 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:58:44 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hash_base(char type, t_pfinfo *e)
{
	if (type == 'o' && e->bf[0] != '0')
		e->ret += write(e->fd, "0", 1);
	else if (type == 'x' || type == 'X')
		e->ret += write(e->fd, type == 'x' ? "0x" : "0X", 2);
}

void	process_precision_base(t_pfinfo *e)
{
	char	*zeros;
	char	*tmp;
	int		i;
	int		len;

	tmp = NULL;
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

void	print_zerowidth_base(char type, t_pfinfo *e)
{
	int	len;
	int	i;

	if (e->flags.hash == 1 && type == 'o')
		len = (int)ft_strlen(e->bf) + 1;
	else if (e->flags.hash == 1 && (type == 'X' || type == 'x'))
		len = (int)ft_strlen(e->bf) + 2;
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

void	print_base(char type, t_pfinfo *e)
{
	if (type != 'o')
		if (e->bf[0] == '0' || e->bf[0] == '\0')
			e->flags.hash = 0;
	process_precision_base(e);
	if (e->flags.minus == 1)
	{
		e->flags.hash == 1 ? print_hash_base(type, e) : 0;
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
		print_zerowidth_base(type, e);
	}
	else if (e->flags.zero == 1)
	{
		e->flags.hash == 1 ? print_hash_base(type, e) : 0;
		print_zerowidth_base(type, e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	else
	{
		print_zerowidth_base(type, e);
		e->flags.hash == 1 ? print_hash_base(type, e) : 0;
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	e->i++;
	free(e->bf);
}
