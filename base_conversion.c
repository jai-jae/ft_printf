/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:48:24 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/22 02:07:30 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_binary(t_pfinfo *input, unsigned long int val)
{
	if (input->mod == mod_non)
		input->output = ft_uitoa_base((unsigned int)val, 2);
	else if (input->mod == mod_hh)
		input->output = ft_uitoa_base((unsigned char)val, 2);
	else if (input->mod == mod_h)
		input->output = ft_uitoa_base((unsigned short int)val, 2);
	else if (input->mod == mod_l || input->mod == mod_j || input->mod == mod_z)
		input->output = ultoa_base((unsigned long int)val, 2);
	else if (input->mod == mod_ll)
		input->output = ulltoa_base((unsigned long long int)val, 2);
}

void	get_octal(t_pfinfo *input, unsigned long int val)
{
	if (input->mod == mod_non)
		input->output = ft_uitoa_base((unsigned int)val, 8);
	else if (input->mod == mod_hh)
		input->output = ft_uitoa_base((unsigned char)val, 8);
	else if (input->mod == mod_h)
		input->output = ft_uitoa_base((unsigned short int)val, 8);
	else if (input->mod == mod_l || input->mod == mod_j || input->mod == mod_z)
		input->output = ultoa_base((unsigned long int)val, 8);
	else if (input->mod == mod_ll)
		input->output = ulltoa_base((unsigned long long int)val, 8);
}

void	get_hexa(t_pfinfo *input, unsigned long int val)
{
	if (input->mod == mod_non)
		input->output = ft_uitoa_base((unsigned int)val, 16);
	else if (input->mod == mod_hh)
		input->output = ft_uitoa_base((unsigned char)val, 16);
	else if (input->mod == mod_h)
		input->output = ft_uitoa_base((unsigned short int)val, 16);
	else if (input->mod == mod_l || input->mod == mod_j || input->mod == mod_z)
		input->output = ultoa_base((unsigned long int)val, 16);
	else if (input->mod == mod_ll)
		input->output = ulltoa_base((unsigned long long int)val, 16);
}
