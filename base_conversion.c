/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:48:24 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:49:39 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_binary(t_pfinfo *e, unsigned long int val)
{
	if (e->mod == mod_non)
		e->bf = ft_uitoa_base((unsigned int)val, 2);
	else if (e->mod == mod_hh)
		e->bf = ft_uitoa_base((unsigned char)val, 2);
	else if (e->mod == mod_h)
		e->bf = ft_uitoa_base((unsigned short int)val, 2);
	else if (e->mod == mod_l || e->mod == mod_j || e->mod == mod_z)
		e->bf = ultoa_base((unsigned long int)val, 2);
	else if (e->mod == mod_ll)
		e->bf = ulltoa_base((unsigned long long int)val, 2);
}

void	get_octal(t_pfinfo *e, unsigned long int val)
{
	if (e->mod == mod_non)
		e->bf = ft_uitoa_base((unsigned int)val, 8);
	else if (e->mod == mod_hh)
		e->bf = ft_uitoa_base((unsigned char)val, 8);
	else if (e->mod == mod_h)
		e->bf = ft_uitoa_base((unsigned short int)val, 8);
	else if (e->mod == mod_l || e->mod == mod_j || e->mod == mod_z)
		e->bf = ultoa_base((unsigned long int)val, 8);
	else if (e->mod == mod_ll)
		e->bf = ulltoa_base((unsigned long long int)val, 8);
}

void	get_hexa(t_pfinfo *e, unsigned long int val)
{
	if (e->mod == mod_non)
		e->bf = ft_uitoa_base((unsigned int)val, 16);
	else if (e->mod == mod_hh)
		e->bf = ft_uitoa_base((unsigned char)val, 16);
	else if (e->mod == mod_h)
		e->bf = ft_uitoa_base((unsigned short int)val, 16);
	else if (e->mod == mod_l || e->mod == mod_j || e->mod == mod_z)
		e->bf = ultoa_base((unsigned long int)val, 16);
	else if (e->mod == mod_ll)
		e->bf = ulltoa_base((unsigned long long int)val, 16);
}
