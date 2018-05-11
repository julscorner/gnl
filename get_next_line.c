/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmurte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:31:52 by jmurte            #+#    #+#             */
/*   Updated: 2018/05/11 14:44:30 by jmurte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
static char	*increase_buf(int const fd, char *oldbuf, int *ret_val)
{
	char	tmp[BUFF_SIZE + 1];
	char	*newbuf;

	*ret_val = read(fd, tmp, BUFF_SIZE);
	tmp[*ret_val] = '\0';
	newbuf = ft_strjoin(oldbuf, tmp);
	ft_strdel(&oldbuf);
	return (newbuf);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (!*buf)
		buf = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			//ft_putnbr(ret);
		//	printf("ret == %d return 1\n", ret);
			return (1);
		}
		buf = increase_buf(fd, buf, &ret);
	}
//	printf("ret == %d\n", ret);
	//ft_putnbr(ret);
	return (ret);
}
