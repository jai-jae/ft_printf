/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:59:26 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/24 21:17:46 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_process_line(int fd, char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (0);
		if (!(tmp = ft_strdup(str[fd] + i + 1)))
			return (0);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])))
			return (0);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*str[FD_NBR];
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(0)))
				return (0);
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (0);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((str[fd] == NULL || str[fd][0] == '\0') && ret == 0)
		return (0);
	return (ft_process_line(fd, str, line));
}
