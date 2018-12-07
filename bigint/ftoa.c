/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 01:06:11 by dolee             #+#    #+#             */
/*   Updated: 2018/12/04 22:19:50 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include <string.h>

char	*printfloat(float f)
{
	t_bigint		*bigint;
	int				bits[23];
	int				i;
	int				tmp;
	unsigned int	utemp;

	i = 22;
	utemp = *(unsigned int *)&f;
	while (i >= 0)
	{
		bits[i] = utemp & 1;
		utemp = utemp >> 1;
		i--;
	}
//	forcal = NULL;
//	forprint = NULL;
//	while (++i < 23)
//	{
//		make(bigint);
//		
//	}
}

t_bigint	*make(t_bigint *prev)
{
	t_bigint	new;

	if (!(new = (t_bigint *)malloc(sizeof(t_bigint))))
		return (NULL);
	new->prev = prev;
	if (!prev)
		prev->next = new;
	new->next = NULL;
	return (new);
}

t_bigint	*addpart(t_bigint *added, t_bigint *adding)
{
	if (!added || !adding)
		return (NULL);
	added->num += adding->num;
	while (added->num >= 100000000)
		if (added->next)
		{
			tmp = added->num / 100000000;
			added->num %= 100000000;
			added = added->next;
			added->num += tmp;
		}
		else
		{
			tmp = added->num / 100000000;
			added->num %= 100000000;
			added = make(added);
			added->num = tmp;
		}
	return (added);
}

t_bigint	*mult10part(t_bigint *multed)
{
	if (!multed)
		return (NULL);
	multed->num *= 10;
	while (multed->num >= 100000000)
		if (multed->next)
		{
			tmp = multed->num / 100000000;
			multed->num %= 100000000;
			multed = multed->next;
			multed->num += tmp;
		}
		else
		{
			tmp = multed->num / 100000000;
			multed->num %= 100000000;
			multed = make(multed);
			multed->num = tmp;
		}
	return (multed);
}

t_bigint	*div2part(t_bigint	*dived)
{
	if (!dived)
		return (NULL);
	dived->num *= 10;
	if ((dived->num % 10) % 2)
	{
		dived->num /= 2;
		dived->prev->num += 100000000;
	}
	else
		dived->num /= 2;
	while (dived->num >= 100000000)
		if (dived->next)
		{
			tmp = dived->num / 100000000;
			dived->num %= 100000000;
			dived = dived->next;
			dived->num = tmp;
		}
		else
		{
			tmp = dived->num / 100000000;
			dived->num %= 100000000;
			dived->make(dived);
			dived->num = tmp;
		}
	return (dived);
}
