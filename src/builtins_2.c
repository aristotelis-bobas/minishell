/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 16:55:24 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 17:30:24 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int		cd_4(t_minishell *sh)
{
	char	*insert;
	char	new[1024];

	if (!getcwd(new, 1024))
	{
		put_error(strerror(errno));
		return (0);
	}
	insert = ft_strjoin("PWD=", new);
	if (!insert)
	{
		put_error(strerror(errno));
		return (0);
	}
	env_add(insert, sh->env);
	free(insert);
	return (1);
}

int		cd_3(t_minishell *sh)
{
	char	*old;
	char	*insert;

	old = get_env(sh, "PWD");
	if (!old)
		return (0);
	insert = ft_strjoin("OLDPWD=", old);
	free(old);
	if (!insert)
	{
		put_error(strerror(errno));
		return (0);
	}
	env_add(insert, sh->env);
	free(insert);
	if (!cd_4(sh))
		return (0);
	return (1);
}

int		cd_2(int ac, char **av, t_minishell *sh)
{
	char	*home;

	if (ac == 1)
	{
		home = get_env(sh, "HOME");
		if (!home)
			return (1);
		if (chdir(home))
		{
			free(home);
			put_error(strerror(errno));
			return (1);
		}
		free(home);
	}
	else if (chdir(av[1]))
	{
		put_error(strerror(errno));
		return (1);
	}
	if (!cd_3(sh))
		return (1);
	return (0);
}

void	cd_1(int ac, char **av, t_minishell *sh)
{
	int		exit;

	exit = 0;
	if (ac > 2)
	{
		put_error("Too many arguments");
		exit = 1;
	}
	else
		exit = cd_2(ac, av, sh);
	exit == 1 ? env_add("?=1", sh->env) : env_add("?=0", sh->env);
}
