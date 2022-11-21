/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:42:31 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/21 15:29:25 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_initialize(char *s, int j)
{
	int	i;

	i = 0;
	if (s[j] == '\0')
		s[i] = '\0';
	else
	{
		while (s[j])
			s[i++] = s[j++];
		s[i] = '\0';
	}
}

char	*ft_cat_char(char *str, char c)
{
	char	*copy;
	int		i;

	i = -1;
	if (!str)
	{
		copy = malloc(sizeof(char) * (2 + ++i));
		if (!copy)
			return (NULL);
	}
	else
	{
		copy = malloc(sizeof(char) * ((int)ft_strlen(str) + 2));
		if (!copy)
		{
			free(str);
			return (NULL);
		}
		while (str[++i])
			copy[i] = str[i];
		free(str);
	}
	copy[i] = c;
	copy[++i] = '\0';
	return (copy);
}

int	ft_is_newline(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
