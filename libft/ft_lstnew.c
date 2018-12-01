/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:24:23 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/25 19:16:13 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*tmp_content;

	tmp_content = NULL;
	tmp = NULL;
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == (NULL))
	{
		tmp->content = (NULL);
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp_content = ft_memalloc(content_size + 1)))
			return (NULL);
		tmp->content = ft_memcpy(tmp_content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = (NULL);
	return (tmp);
}
