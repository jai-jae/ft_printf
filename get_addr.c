/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:02:40 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/30 11:17:52 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*get_addr(unsigned long long int n, unsigned long long int base)
{
	char					*addr;
	int						len;
	unsigned long long int	tmp;
	
	len = 1;
	tmp = n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(addr = ft_memalloc(len + 3)))
		return (NULL);
	len = len + 2;
	addr[len] = '\0';
	addr[0] = '0';
	addr[1] = 'x';
	tmp = n;
	while (tmp >= 16)
	{
		addr[--len] = tmp % base > 9 ?
			(tmp % base) + 87 : (tmp % base) + '0';
		tmp /= base;
	}
	addr[--len] = tmp % base > 9 ?
		(tmp % base) + 87 : (tmp % base) + '0';
	return (addr);
}
