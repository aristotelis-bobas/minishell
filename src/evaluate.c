/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:50:21 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/19 00:32:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>

void	evaluate_line(int arg_count, char **args, t_minishell *sh)
{
	if (!ft_strcmp(args[0], "exit"))
		exit(0);
	if (!ft_strcmp(args[0], "pwd"))
		pwd();
	else if (!ft_strcmp(args[0], "cd"))
		cd(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "echo"))
		echo(arg_count, args);
	else if (!ft_strcmp(args[0], "env"))
		vector_print(sh->env);
	else if (!ft_strcmp(args[0], "export"))
		export(arg_count, args, sh);
	else if (!ft_strcmp(args[0], "unset"))
		unset(arg_count, args, sh);
	else
		execute(args, sh);
}

void	evaluate(t_minishell *sh)
{
	int		i;
	
	i = 0;
	while (i < sh->line_count)
	{
		evaluate_line(sh->arg_count[i], sh->args[i], sh);
		i++;
	}
}

