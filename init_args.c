/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:10:07 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/05 17:24:20 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_int_arg(t_pfinfo *input, long int *val)
{
	if (input->mod == mod_non)
		*val = (long int)va_arg(input->ap, int);
	else if (input->mod == mod_hh)
		*val = (long int)va_arg(input->ap, char);
	else if (input->mod == mod_h)
		*val = (long int)va_arg(input->ap, short int);
	else if (input->mod == mod_l)
		*val = (long int)va_arg(input->ap, long int);
	else if (input->mod == mod_ll)
		*val = (long int)va_arg(input->ap, long int);
}

void	init_uint_arg(t_pfinfo *input, unsigned long int *val)
{
	if (input->mod == mod_non)
		*val = (unsigned long int)va_arg(input->ap, unsigned int);
	else if (input->mod == mod_hh)
		*val = (unsigned long int)va_arg(input->ap, unsigned char);
	else if (input->mod == mod_h)
		*val = (unsigned long int)va_arg(input->ap, unsigned short int);
	else if (input->mod == mod_l)
		*val = (unsigned long int)va_arg(input->ap, unsigned long int);
	else if (input->mod == mod_ll)
		*val = (unsigned long int)va_arg(input->ap, unsigned long int);
}

void	init_float_arg(t_pfinfo *input, long double *val)
{
	if (input->mod == mod_non)
		*val = (long double)va_arg(input->ap, float);
	else if (input->mod == mod_l)
		*val = (long double)va_arg(input->ap, double);
	else if (input->mod == mod_L)
		*val = (long double)va_arg(input->ap, long double);
}
