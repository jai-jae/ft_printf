/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:21:20 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:59:46 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		print_width_addr(t_pfinfo *e)
{
	int len;
	int i;

	len = ft_strlen(e->bf) + 2;
	i = e->flags.width - len;
	while (i > 0)
	{
		e->ret += (e->flags.zero == 1 ?
				write(e->fd, "0", 1) : write(e->fd, " ", 1));
		i--;
	}
}

int			addr_precision(t_pfinfo *e)
{
	char	*tmp;
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(e->bf);
	if (e->flags.prec > len)
	{
		i = e->flags.prec - len;
		if (!(tmp = ft_strnew(i)))
			return (0);
		while (i > 0)
			tmp[--i] = '0';
		if (!(new = ft_strjoin(tmp, e->bf)))
			return (0);
		free(tmp);
		free(e->bf);
		e->bf = new;
	}
	return (1);
}

void		print_addr(t_pfinfo *e)
{
	e->flags.space = 0;
	e->flags.plus = 0;
	addr_precision(e);
	if (!(addr_precision(e)))
		return ;
	if (e->flags.minus == 1)
	{
		print_hash_base('x', e);
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
		print_width_addr(e);
	}
	else
	{
		e->flags.zero == 0 ? print_width_addr(e) : 0;
		print_hash_base('x', e);
		e->flags.zero == 1 ? print_width_addr(e) : 0;
		e->ret += write(e->fd, e->bf, ft_strlen(e->bf));
	}
	e->i++;
	free(e->bf);
}
