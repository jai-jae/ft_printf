/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:20:49 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 22:05:38 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpoint.h"
#include "bigint.h"

static unsigned char	*output_mix(t_fprec *nbr, unsigned char *ret,
						unsigned char *bcd, int sig_len)
{
	int	index_ret;
	int	index_bcd;

	if (!(ret = (unsigned char *)malloc(sizeof(unsigned char) * (sig_len + 2))))
		return (NULL);
	index_ret = 0;
	index_bcd = 0;
	while (bcd[index_bcd])
	{
		ret[index_ret] = bcd[index_bcd];
		if (index_ret == sig_len - (nbr->len_sosu - nbr->exp))
		{
			ret[index_ret] = '.';
			nbr->dot = index_ret;
			index_bcd -= 1;
		}
		index_ret++;
		index_bcd++;
	}
	ret[index_ret] = '\0';
	return (ret);
}

static unsigned char	*output_deci(t_fprec *nbr, unsigned char *ret,
						unsigned char *bcd, int sig_len)
{
	int	index_ret;
	int	index_bcd;
	int	zeros;

	zeros = nbr->len_sosu - nbr->exp - sig_len;
	if (!(ret = (unsigned char *)malloc(sizeof(*ret) * (sig_len + 3 + zeros))))
		return (NULL);
	ret[0] = '0';
	ret[1] = '.';
	index_ret = 2;
	index_bcd = 0;
	while (zeros > 0)
	{
		ret[index_ret] = '0';
		zeros--;
		index_ret++;
	}
	while (bcd[index_bcd])
	{
		ret[index_ret] = bcd[index_bcd];
		index_ret++;
		index_bcd++;
	}
	ret[index_ret] = '\0';
	return (ret);
}

static unsigned char	*output_inte(t_fprec *nbr, unsigned char *ret,
						unsigned char *bcd, int sig_len)
{
	int	index_ret;
	int	index_bcd;

	index_ret = 0;
	index_bcd = 0;
	if (!(ret = (unsigned char *)malloc(sizeof(unsigned char) * (sig_len + 3))))
		return (NULL);
	while (bcd[index_bcd])
	{
		ret[index_ret] = bcd[index_bcd];
		index_ret++;
		index_bcd++;
	}
	nbr->dot = index_ret;
	ret[index_ret] = '.';
	ret[index_ret + 1] = '0';
	ret[index_ret + 2] = '\0';
	return (ret);
}

unsigned char			*process_output(t_fprec *nbr, unsigned char *bcd,
						int sig_len)
{
	unsigned char	*ret;
	int				nbr_zeros;
	int				i;

	i = 0;
	ret = NULL;
	while (i < sig_len)
	{
		bcd[i] = bcd[i] + '0';
		i++;
	}
	nbr_zeros = nbr->len_sosu - nbr->exp;
	if (nbr_zeros <= 0 && nbr->exp >= 0)
		ret = output_inte(nbr, ret, bcd, sig_len);
	else if (nbr_zeros >= 0 && nbr->exp >= 0)
		ret = output_mix(nbr, ret, bcd, sig_len);
	else if (nbr_zeros >= 0 && nbr->exp < 0)
		ret = output_deci(nbr, ret, bcd, sig_len);
	return (ret);
}
