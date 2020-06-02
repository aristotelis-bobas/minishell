/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:50:21 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/29 18:14:07 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void	evaluate_commands(int arg_count, char **args, t_minishell *sh)
{
	if (!ft_strcmp(args[0], "exit"))
		ft_exit(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "pwd"))
		pwd(sh);
	else if (!ft_strcmp(args[0], "cd"))
		cd_1(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "echo"))
		echo(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "env"))
		env_show(sh);
	else if (!ft_strcmp(args[0], "export"))
		export_1(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "unset"))
		unset(arg_count, args, sh);
	else
		execute(args, sh);
}

void	export_command(char *arg, t_minishell *sh)
{
	char	*insert;

	insert = ft_strjoin("_=", arg);
	if (!insert)
	{
		put_error(strerror(errno));
		return ;
	}
	env_add(insert, sh->env);
	free(insert);
}

void	set_file_descriptor(t_minishell *sh, int i)
{
	if (sh->file_descriptor[i][0])
	{
		if ((dup2(sh->file_descriptor[i][1], 1)) < 0)
			put_error(strerror(errno));
		close(sh->file_descriptor[i][1]);
	}
	if (sh->file_descriptor[i][2])
	{
		if ((dup2(sh->file_descriptor[i][3], 0)) < 0)
			put_error(strerror(errno));
		close(sh->file_descriptor[i][3]);
	}
}

void	reset_file_descriptor(t_minishell *sh, int i)
{
	if (sh->file_descriptor[i][0])
	{
		if ((dup2(sh->saved_stdout, 1)) < 0)
			put_error(strerror(errno));
	}
	if (sh->file_descriptor[i][2])
	{
		if ((dup2(sh->saved_stdin, 0)) < 0)
			put_error(strerror(errno));
	}
}

void	evaluate(t_minishell *sh)
{
	int		i;

	i = 0;
	while (i < sh->line_count)
	{
		export_command(sh->args[i][0], sh);
		set_file_descriptor(sh, i);
		evaluate_commands(sh->arg_count[i], sh->args[i], sh);
		reset_file_descriptor(sh, i);
		i++;
	}
}
