/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:40:11 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/16 15:51:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			reading;

	if (fd < 0)
		return (NULL);
	reading = 1;
	str = NULL;
	while (reading != -1 && reading)
	{
		if (ft_is_newline(buf))
			return (ft_cut_buf(str, buf));
		if (*buf)
			str = ft_add_buf(str, buf);
		reading = read(fd, buf, BUFFER_SIZE);
		buf[reading] = '\0';
	}
	if (!reading)
	{
		buf[0] = '\0';
		return (str);
	}
	return (NULL);
}
