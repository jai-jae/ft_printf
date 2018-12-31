/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:10:07 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/28 15:35:43 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_int_arg(t_pfinfo *input, long int *val)
{
	if (input->mod == mod_non)
		*val = (long int)va_arg(input->ap, int);
	else if (input->mod == mod_hh)
		*val = (long int)va_arg(input->ap, int);
	else if (input->mod == mod_h)
		*val = (long int)va_arg(input->ap, int);
	else if (input->mod == mod_l || input->mod == mod_z)
		*val = (long int)va_arg(input->ap, long int);
	else if (input->mod == mod_ll || input->mod == mod_j)
		*val = (long int)va_arg(input->ap, long int);
}

void	init_uint_arg(char type, t_pfinfo *input, unsigned long int *val)
{
	if (type == 'U')
		*val = (unsigned long int)va_arg(input->ap, unsigned long int);
	else
	{
		if (input->mod == mod_non)
			*val = (unsigned long int)va_arg(input->ap, unsigned int);
		else if (input->mod == mod_hh)
			*val = (unsigned long int)va_arg(input->ap, unsigned int);
		else if (input->mod == mod_h)
			*val = (unsigned long int)va_arg(input->ap, unsigned int);
		else if (input->mod == mod_l || input->mod == mod_z)
			*val = (unsigned long int)va_arg(input->ap, unsigned long int);
		else if (input->mod == mod_ll || input->mod == mod_j)
			*val = (unsigned long int)va_arg(input->ap, unsigned long int);
	}
}
