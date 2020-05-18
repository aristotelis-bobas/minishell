/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_read.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 20:29:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/19 00:23:16 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*parse_read_line(int fd, int buf_size)
{
	char	*dst;
	char	byte;
	int		ret;
	int		i;

	dst = (char*)malloc(sizeof(char) * buf_size);
	if (!dst)
		return (0);
	i = 0;
	while (1)
	{
		if ((ret = read(fd, &byte, 1)) < 0)
			return (0);
		if (ret == 0)
			exit(0);
		dst[i] = (byte == '\n' || byte == '\0') ? '\0' : byte;
		if (byte == '\n' || byte == '\0')
			return (dst);
		i++;
		if (i == buf_size)
		{
			buf_size += 64;
			dst = ft_realloc(dst, buf_size - 64, buf_size);
			if (!dst)
				return (0);
		}
	}
}

int		parse_read(t_minishell *sh)
{
	sh->line = parse_read_line(0, 128);
	if (!sh->line)
	{
		put_error(strerror(errno));
		return (0);
	}
	if (sh->line[0] == '\0')
		return (0);
	return (1);
}