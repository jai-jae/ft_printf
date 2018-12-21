/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:21:20 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:25:34 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		print_width_addr(t_pfinfo *input)
{
	int len;
	int i;

	len = ft_strlen(input->output) + 2;
	i = input->flags.width - len;
	while (i > 0)
	{
		input->ret += write(1, " ", 1);
		i--;
	}
}

int			addr_precision(t_pfinfo *input)
{
	char	*tmp;
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(input->output);
	if (input->flags.prec > len)
	{
		i = input->flags.prec - len;
		if (!(tmp = ft_strnew(i)))
			return (0);
		while (i > 0)
			tmp[--i] = '0';
		if (!(new = ft_strjoin(tmp, input->output)))
			return (0);
		free(tmp);
		free(input->output);
		input->output = new;
	}
	return (1);
}

void		print_addr(t_pfinfo *input)
{
	input->flags.space = 0;
	input->flags.plus = 0;
	addr_precision(input);
	if (!(addr_precision(input)))
		return ;
	if (input->flags.minus == 1)
	{
		print_hash_base('x', input);
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_width_addr(input);
	}
	else
	{
		print_hash_base('x', input);
		print_width_addr(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
	free(input->output);
}
