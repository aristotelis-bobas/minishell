/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe_3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 23:35:08 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 00:28:05 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		count_pipe_args_2(t_minishell *sh, int *arg_count, int j, int y)
{
	int		x;

	x = 0;
	arg_count[j] = 0;
	while (sh->args[y][x] != 0)
	{
		if (!ft_strcmp(sh->args[y][x], "|"))
		{
			j++;
			arg_count[j] = 0;
		}
		else
			arg_count[j]++;
		x++;
	}
	return (j);
}

int		*count_pipe_args_1(t_minishell *sh, int *arg_count, int i)
{
	int		j;
	int		y;

	j = 0;
	y = 0;
	while (y < sh->line_count)
	{
		if (y != i)
			arg_count[j] = sh->arg_count[y];
		else
			j = count_pipe_args_2(sh, arg_count, j, y);
		j++;
		y++;
	}
	return (arg_count);
}

int		fill_pipe_data_3(int **data, t_minishell *sh, int i, int x)
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
			data[x][z] = sh->data[i][y];
			z++;
		}
		y++;
	}
	return (x);
}

int		fill_pipe_data_2(int **data, t_minishell *sh, int i, int x)
{
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < sh->arg_count[i])
	{
		data[x][z] = sh->data[i][y];
		z++;
		y++;
	}
	return (1);
}

int		**fill_pipe_data_1(int **data, t_minishell *sh, int a)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < sh->line_count)
	{
		if (i != a)
			fill_pipe_data_2(data, sh, i, x);
		else
			x = fill_pipe_data_3(data, sh, i, x);
		x++;
		i++;
	}
	return (data);
}
