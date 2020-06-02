/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_read.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 20:29:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 19:28:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

char	*parse_read_line(int buf_size, int i, char *dst)
{
	int		ret;
	char	byte;

	while (1)
	{
		ret = read(0, &byte, 1);
		if (ret < 0)
		{
			free(dst);
			return (0);
		}
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
	char	*dst;
	int		i;

	dst = (char*)malloc(sizeof(char) * 128);
	if (!dst)
	{
		put_error(strerror(errno));
		return (0);
	}
	i = 0;
	sh->line = parse_read_line(128, i, dst);
	if (!sh->line)
	{
		put_error(strerror(errno));
		return (0);
	}
	if (sh->line[0] == '\0')
		return (0);
	return (1);
}
