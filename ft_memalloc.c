/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:46:43 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/10 20:59:56 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = (NULL);
	if (size)
	{
		if (!(ptr = malloc(size)))
			return (NULL);
		else
			ft_bzero(ptr, size);
	}
	return (ptr);
}
