/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:49:07 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/17 13:04:25 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;
	t_list	*tmp_new;

	if (!(lst && f))
		return (NULL);
	tmp_new = (NULL);
	begin_list = (NULL);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	begin_list = new;
	tmp_new = new;
	lst = lst->next;
	while (lst != (NULL))
	{
		if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		tmp_new->next = new;
		tmp_new = new;
		lst = lst->next;
	}
	return (begin_list);
}
