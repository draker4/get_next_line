/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:40:11 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/21 15:57:44 by bperriol         ###   ########lyon.fr   */
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
	free(str);
	return (NULL);
}

char	*ft_add_buf(char *str, char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		str = ft_cat_char(str, buf[i++]);
		if (!str)
			return (NULL);
	}
	return (str);
}

void	ft_buf_last_char(char *buf, int reading)
{
	if (!reading || reading == -1)
		buf[0] = '\0';
	else
		buf[reading] = '\0';
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
		{
			str = ft_add_buf(str, buf);
			if (!str)
				return (NULL);
		}
		reading = read(fd, buf, BUFFER_SIZE);
		ft_buf_last_char(buf, reading);
	}
	if (!reading)
		return (str);
	free(str);
	return (NULL);
}
