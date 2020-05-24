/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 00:25:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 13:23:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void	signal_catch()
{
}

void	exit_status(int exit, t_minishell *sh)
{
	char	*number;
	char	*insert;

	if (!(number = ft_itoa(exit)))
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

	while (1)
	{
		signal(SIGINT, signal_catch);
		signal(SIGQUIT, signal_catch);
		wait(&status);												
		if (WIFEXITED(status))
		{					
			exit = WEXITSTATUS(status);	
			if (!exit)
				env_add("?=0", sh->env);
			else
				exit_status(exit, sh);
			return ;
		}
	}
}

void	execute(char **av, t_minishell *sh)
{
	pid_t	pid;

	if (!(av[0] = get_executable(av[0], sh)))
		return ;
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno));
	else if (pid == 0)
	{
		if (execve(av[0], av, sh->env->data) < 0)
		{
			put_error("Command not found");
			exit(127);
		}
	}
	else
		waiting(sh);
}
