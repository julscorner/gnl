/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmurte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:18:39 by jmurte            #+#    #+#             */
/*   Updated: 2018/05/23 19:40:16 by jmurte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2

# include "libft/libft.h"

char		*increase_buf(int fd, char *oldbuf, int *ret_val, int *err);
char		*line_with_newline(char *str, char **line, char *buf);
int			line_without_linefeed(char **line, char *buf);
int			get_next_line(int const fd, char **line);

#endif
