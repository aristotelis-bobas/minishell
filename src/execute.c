/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 00:25:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/19 01:20:46 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	execute(char **av, t_minishell *sh)
{
	pid_t	pid;
	char	*executable;
	int		status;

	if (!(executable = ft_strjoin("/bin/", av[0])))
		return ;
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno));
	else if (pid == 0)
	{
		if (execve(executable, av, sh->env->data) < 0)
		{
			put_error(strerror(errno));
			exit(1);
		}
	}
	else
	{
		while (!WIFEXITED(status))
			wait(&status);
	}	
}
