/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sanitize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:18:52 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 14:31:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int		count_lines(t_minishell *sh)
{
	int		i;
	int		count;
	
	count = 0;
	i = 0;
	while (i < sh->line_count)
	{
		if (sh->arg_count[i] != 0)
			count++;
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

char    		***fill_array(t_minishell *sh, char ***array, int line_count, int *arg_count)
{
	int		i;
	int		y;
	int		x;
	int		z;
	
	i = 0;
	x = 0;
	while (i < sh->line_count)
	{
		if (sh->arg_count[i] != 0)
		{
			y = 0;
			z = 0;
			while (y < sh->arg_count[i])
			{
				if (sh->args[i][y] != 0)
				{
					if (!(array[x][z] = ft_strdup(sh->args[i][y])))
					{
						put_error(strerror(errno));
						free_array(array, line_count, arg_count);
						return (0);	
					}
					z++;
				}
				y++;
			}
			x++;
		}
		i++;
	}
	return (array);
}

int				parse_sanitize(t_minishell *sh)
{
	int		line_count;
	int		*arg_count;
	char	***array;

	line_count = count_lines(sh);
	if (!(arg_count = allocate_counter(line_count)))
		return (0);
	arg_count = count_args(sh, arg_count);
	if (!(array = allocate_array(line_count, arg_count)))
		return (0);
	if (!(array = fill_array(sh, array, line_count, arg_count)))
		return (0);
	free_array(sh->args, sh->line_count, sh->arg_count);
	free(sh->arg_count);
	sh->args = array;
	sh->line_count = line_count;
	sh->arg_count = arg_count;
	return (1);
}