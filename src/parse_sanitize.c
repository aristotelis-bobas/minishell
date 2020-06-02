/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sanitize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:18:52 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/26 17:18:09 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int		count_lines(t_minishell *sh)
{
	int		i;
	int		y;
	int		count;

	count = 0;
	i = 0;
	while (i < sh->line_count)
	{
		y = 0;
		while (y < sh->arg_count[i])
		{
			if (sh->args[i][y] != 0)
			{
				count++;
				break ;
			}
			y++;
		}
		i++;
	}
	return (count);
}

static int		*count_args(t_minishell *sh, int *arg_count)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	while (i < sh->line_count)
	{
		if (sh->arg_count[i] != 0)
		{
			arg_count[y] = 0;
			x = 0;
			while (x < sh->arg_count[i])
			{
				if (sh->args[i][x] != 0)
					arg_count[y]++;
				x++;
			}
			y++;
		}
		i++;
	}
	return (arg_count);
}

char			***fill_array(t_minishell *sh, char ***arr, int line, int *arg)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < sh->line_count)
	{
		if (sh->arg_count[i] != 0)
		{
			if (!array_helper(sh, arr, i, x))
			{
				put_error(strerror(errno));
				free_array(arr, line, arg);
				return (0);
			}
			x++;
		}
		i++;
	}
	return (arr);
}

int				**fill_data(int **data, t_minishell *sh)
{
	int		i;
	int		y;
	int		x;
	int		z;

	i = 0;
	x = 0;
	while (i < sh->line_count)
	{
		y = 0;
		z = 0;
		if (sh->arg_count[i] != 0)
			while (y < sh->arg_count[i])
			{
				if (sh->args[i][y] != 0)
				{
					data[x][z] = sh->data[i][y];
					z++;
				}
				y++;
			}
		x = (sh->arg_count[i] != 0) ? x + 1 : x;
		i++;
	}
	return (data);
}

int				parse_sanitize(t_minishell *sh)
{
	int		line_count;
	int		*arg_count;
	char	***array;

	line_count = count_lines(sh);
	arg_count = allocate_counter(line_count);
	if (!arg_count)
		return (0);
	arg_count = count_args(sh, arg_count);
	array = allocate_array(line_count, arg_count);
	if (!array)
		return (0);
	array = fill_array(sh, array, line_count, arg_count);
	if (!array)
		return (0);
	if (sh->data)
		if (!sanitize_data(sh, line_count, arg_count))
			return (0);
	free_array(sh->args, sh->line_count, sh->arg_count);
	free(sh->arg_count);
	sh->args = array;
	sh->line_count = line_count;
	sh->arg_count = arg_count;
	return (1);
}
