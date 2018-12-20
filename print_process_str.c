/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proess_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:52:54 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:30:08 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_zerowidth_str(t_pfinfo *input)
{
	int	len;
	int	i;

	len = ft_strlen(input->output);
	i = input->flags.width - len;
	while (i > 0)
	{
		input->ret += ((input->flags.zero) == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
		i--;
	}
}

void	print_str(t_pfinfo *input)
{
	char	*tmp;

	input->flags.space = 0;
	input->flags.plus = 0;
	input->flags.hash = 0;
	if (input->flags.prec >= 0 && input->flags.prec <= ft_strlen(input->output))
	{
		tmp = ft_strsub(input->output, 0, input->flags.prec);
		free(input->output);
		input->output = tmp;
	}
	if (!(input->output))
		return ;
	if (input->flags.minus == 1)
	{
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_zerowidth_str(input);
	}
	else
	{
		print_zerowidth_str(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
	free(input->output);
}
