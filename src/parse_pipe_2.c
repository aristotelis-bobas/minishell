/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 00:02:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 00:25:55 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <unistd.h>

int		array_pipe_helper(t_minishell *sh, char ***arr, int i, int x)
{
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < sh->arg_count[i])
	{
		if (!ft_strcmp(sh->args[i][y], "|"))
		{
			x++;
			z = 0;
		}
		else
		{
			arr[x][z] = ft_strdup(sh->args[i][y]);
			if (!arr[x][z])
				return (0);
			z++;
		}
		y++;
	}
	return (1);
}

char	***fill_pipe_array(t_minishell *sh, char ***arr, int i)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < sh->line_count)
	{
		if (y != i)
		{
			if (!array_helper(sh, arr, y, x))
				return (0);
			x++;
		}
		else
		{
			if (!array_pipe_helper(sh, arr, y, x))
				return (0);
			x = x + count_pipes(sh->args[y]) + 1;
		}
		y++;
	}
	return (arr);
}

int		connect_pipes(int **file_descriptor, int x)
{
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (0);
	file_descriptor[x][0] = 1;
	file_descriptor[x][1] = pipefd[1];
	file_descriptor[x + 1][2] = 1;
	file_descriptor[x + 1][3] = pipefd[0];
	return (1);
}

int		pipe_file_descriptor(int **file_descriptor, \
		t_minishell *sh, int i, int x)
{
	int		count;
	int		j;

	j = 0;
	count = count_pipes(sh->args[i]);
	while (j < count)
	{
		if (!connect_pipes(file_descriptor, x))
			return (-1);
		j++;
		x++;
	}
	return (x);
}

int		**fill_pipe_file_descriptor(int **file_descriptor, \
		t_minishell *sh, int i)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < sh->line_count)
	{
		if (y != i)
		{
			file_descriptor[x][0] = sh->file_descriptor[y][0];
			file_descriptor[x][1] = sh->file_descriptor[y][1];
			file_descriptor[x][2] = sh->file_descriptor[y][2];
			file_descriptor[x][3] = sh->file_descriptor[y][3];
			x++;
		}
		else
		{
			x = pipe_file_descriptor(file_descriptor, sh, i, x);
			if (x < 0)
				return (0);
			y = y + count_pipes(sh->args[i]);
		}
		y++;
	}
	return (file_descriptor);
}
