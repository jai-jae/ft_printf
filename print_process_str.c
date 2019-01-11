/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proess_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:52:54 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 22:00:43 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_zerowidth_str(t_pfinfo *e)
{
	int	len;
	int	i;

	len = ft_strlen(e->bf);
	i = e->flags.width - len;
	while (i > 0)
	{
		e->ret += ((e->flags.zero) == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		i--;
	}
}

void	print_null_str(t_pfinfo *e)
{
	int	len;
	int i;

	len = e->flags.prec < 0 ? 6 : e->flags.prec;
	i = e->flags.width - len;
	while (i > 0)
	{
		e->ret += ((e->flags.zero) == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		i--;
	}
	e->ret += write(e->fd, "(null)", len);
	e->i++;
}

void	print_str(t_pfinfo *e)
{
	char	*tmp;

	if (e->flags.prec >= 0 &&
			e->flags.prec <= (int)ft_strlen(e->bf))
	{
		tmp = ft_strsub(e->bf, 0, e->flags.prec);
		free(e->bf);
		e->bf = tmp;
	}
	if (!(e->bf))
		return ;
	if (e->flags.minus == 1)
	{
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
		print_zerowidth_str(e);
	}
	else
	{
		print_zerowidth_str(e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	e->i++;
	free(e->bf);
}
