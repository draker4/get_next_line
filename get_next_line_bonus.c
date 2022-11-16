/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:40:11 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/16 12:05:08 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line_in_buf(char *buf)
{
	int		i;
	char	*copy;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		copy[i] = buf[i];
		i++;
	}
	copy[i++] = '\n';
	copy[i] = '\0';
	ft_initialize(buf, i);
	return (copy);
}

char	*ft_cut_buf(char *str, char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		str = ft_cat_char(str, buf[i]);
		if (!str)
			return (NULL);
		if (buf[i] == '\n')
		{
			ft_initialize(buf, i + 1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_add_buf(char *str, char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
		str = ft_cat_char(str, buf[i++]);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			reading;

	if (fd < 0)
		return (NULL);
	reading = 1;
	str = NULL;
	while (reading != -1 && reading)
	{
		if (ft_is_newline(buf[fd]))
			return (ft_cut_buf(str, buf[fd]));
		if (*(buf[fd]))
			str = ft_add_buf(str, buf[fd]);
		reading = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][reading] = '\0';
	}
	if (!reading)
	{
		buf[fd][0] = '\0';
		return (str);
	}
	return (NULL);
}
