/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:42:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/16 12:00:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	char	*str2;

	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open a renvoye une erreur\n");
		return (1);
	}
	str = get_next_line(-10);
	str2 = get_next_line(-5);
	while (str || str2)
	{
		printf("%s", str);
		printf("%s", str2);
		free(str);
		str = get_next_line(-10);
		str2 = get_next_line(-5);
	}
	free(str);
	return (0);
}
