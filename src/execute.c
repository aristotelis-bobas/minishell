/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 00:25:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/01 16:36:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	exit_status(int exit, t_minishell *sh)
{
	char	*number;
	char	*insert;

	number = ft_itoa(exit);
	if (!number)
	{
		put_error(strerror(errno));
		return ;
	}
	insert = ft_strjoin("?=", number);
	free(number);
	if (!insert)
	{
		put_error(strerror(errno));
		return ;
	}
	env_add(insert, sh->env);
	free(insert);
}

void	waiting(t_minishell *sh)
{
	int		status;
	int		exit;

	signal_handler_child();
	while (1)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit = WEXITSTATUS(status);
			exit_status(exit, sh);
			return ;
		}
		if (WIFSIGNALED(status))
		{
			ft_printf("\n");
			exit = WTERMSIG(status);
			exit_status(exit + 128, sh);
			return ;
		}
	}
}

void	child_process(char **av, t_minishell *sh)
{
	if (execve(av[0], av, sh->env->data) < 0)
	{
		if (errno == 2)
		{
			put_error("Command not found");
			exit(127);
		}
		else
		{
			put_error(strerror(errno));
			exit(126);
		}
	}
}

void	execute(char **av, t_minishell *sh)
{
	pid_t	pid;

	av[0] = get_executable(av[0], sh);
	if (!av[0])
		return ;
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno));
	else if (pid == 0)
		child_process(av, sh);
	else
		waiting(sh);
}
