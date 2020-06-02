/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 15:42:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 00:43:53 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int		split_pipe_4(t_minishell *sh, char ***arr, int line, int *arg)
{
	free_array(sh->args, sh->line_count, sh->arg_count);
	free(sh->arg_count);
	sh->args = arr;
	sh->line_count = line;
	sh->arg_count = arg;
	return (1);
}

int		split_pipe_3(t_minishell *sh, int i, int line, int *arg)
{
	int			**data;
	int			**file_descriptor;

	data = allocate_data(line, arg);
	if (!data)
		return (0);
	data = fill_pipe_data_1(data, sh, i);
	file_descriptor = allocate_file_descriptor(line);
	if (!file_descriptor)
	{
		free_data(data, line);
		return (0);
	}
	file_descriptor = fill_pipe_file_descriptor(file_descriptor, sh, i);
	if (!file_descriptor)
	{
		free_data(data, line);
		return (0);
	}
	free_file_descriptor(sh->file_descriptor, sh->line_count);
	free_data(sh->data, sh->line_count);
	sh->file_descriptor = file_descriptor;
	sh->data = data;
	return (1);
}

char	***split_pipe_2(t_minishell *sh, int line, int *arg, int i)
{
	char	***array;

	array = allocate_array(line, arg);
	if (!array)
	{
		free(arg);
		return (0);
	}
	array = fill_pipe_array(sh, array, i);
	if (!array)
	{
		put_error(strerror(errno));
		free_array(array, line, arg);
		free(arg);
		return (0);
	}
	return (array);
}

int		split_pipe_1(t_minishell *sh, int i)
{
	char		***array;
	int			*arg_count;
	int			line_count;

	line_count = sh->line_count + count_pipes(sh->args[i]);
	arg_count = allocate_counter(line_count);
	if (!arg_count)
		return (0);
	arg_count = count_pipe_args_1(sh, arg_count, i);
	array = split_pipe_2(sh, line_count, arg_count, i);
	if (!array)
		return (0);
	if (!split_pipe_3(sh, i, line_count, arg_count))
	{
		free_array(array, line_count, arg_count);
		free(arg_count);
		return (0);
	}
	split_pipe_4(sh, array, line_count, arg_count);
	return (1);
}

int		parse_pipe(t_minishell *sh)
{
	int		i;

	i = 0;
	sh->file_descriptor = allocate_file_descriptor(sh->line_count);
	if (!sh->file_descriptor)
		return (0);
	while (i < sh->line_count)
	{
		if (check_pipes(sh->args[i]))
		{
			if (!split_pipe_1(sh, i))
				return (0);
			else
			{
				i = 0;
				continue ;
			}
		}
		i++;
	}
	return (1);
}
