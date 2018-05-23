/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmurte <jmurte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:31:52 by jmurte            #+#    #+#             */
/*   Updated: 2018/05/23 19:39:35 by jmurte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*increase_buf(int fd, char *oldbuf, int *ret_val, int *err)
{
	char	tmp[BUFF_SIZE + 1];
	char	*newbuf;

	*ret_val = read(fd, tmp, BUFF_SIZE);
	if (*ret_val == -1)
	{
		*err = 1;
		*ret_val = 0;
	}
	tmp[*ret_val] = '\0';
	newbuf = ft_strjoin(oldbuf, tmp);
	ft_strdel(&oldbuf);
	return (newbuf);
}

char			*line_with_newline(char *str, char **line, char *buf)
{
	*str = '\0';
	*line = ft_strdup(buf);
	ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
	return (*line);
}

int				line_without_linefeed(char **line, char *buf)
{
	*line = ft_strdup(buf);
	*buf = '\0';
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;
	int				err;

	ret = 1;
	err = 0;
	if (!line || fd < 0)
		return (-1);
	if (!*buf)
		buf = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')))
		{
			*line = line_with_newline(str, line, buf);
			return (1);
		}
		buf = increase_buf(fd, buf, &ret, &err);
		if (err == 1)
			return (-1);
	}
	if (*buf)
		ret = line_without_linefeed(line, buf);
	return (ret);
}
