/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:10:07 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:51:00 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_int_arg(t_pfinfo *e, long int *val)
{
	if (e->mod == mod_non)
		*val = (long int)va_arg(e->ap, int);
	else if (e->mod == mod_hh)
		*val = (long int)va_arg(e->ap, int);
	else if (e->mod == mod_h)
		*val = (long int)va_arg(e->ap, int);
	else if (e->mod == mod_l || e->mod == mod_z)
		*val = (long int)va_arg(e->ap, long int);
	else if (e->mod == mod_ll || e->mod == mod_j)
		*val = (long int)va_arg(e->ap, long int);
}

void	init_uint_arg(char type, t_pfinfo *e, unsigned long int *val)
{
	if (type == 'U')
		*val = (unsigned long int)va_arg(e->ap, unsigned long int);
	else
	{
		if (e->mod == mod_non)
			*val = (unsigned long int)va_arg(e->ap, unsigned int);
		else if (e->mod == mod_hh)
			*val = (unsigned long int)va_arg(e->ap, unsigned int);
		else if (e->mod == mod_h)
			*val = (unsigned long int)va_arg(e->ap, unsigned int);
		else if (e->mod == mod_l || e->mod == mod_z)
			*val = (unsigned long int)va_arg(e->ap, unsigned long int);
		else if (e->mod == mod_ll || e->mod == mod_j)
			*val = (unsigned long int)va_arg(e->ap, unsigned long int);
	}
}
