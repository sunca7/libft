/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:55:00 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/30 15:30:16 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_newline(char **line, char **str, const int fd, ssize_t ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n')
	{
		if (!(*line = ft_strndup(str[fd], i)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + i + 1)))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		return (1);
	}
	else if (str[fd][i] == '\0' && ret == 0)
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		str[fd] = ft_strchr(str[fd], '\0');
		return (1);
	}
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char *str[FD];

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buf)))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		ret = read_newline(line, str, fd, ret);
		if (ret == 1 || ret == -1)
			return (ret);
	}
	if (ret == 0 && ft_strlen(str[fd]) > 0)
	{
		ret = read_newline(line, str, fd, ret);
		if (ret == 1 || ret == -1)
			return (ret);
	}
	return (ret);
}
