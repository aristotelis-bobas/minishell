/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/22 21:28:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

void	echo(int ac, char **av, t_minishell *sh)
{
	int		newline;
	int		i;

	newline = 1;
	i = 1;
	if (ac > 1)
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			newline = 0;
			i++;
		}
		while (i < ac)
		{
			ft_printf("%s", av[i]);
			if (i + 1 != ac)
				ft_printf(" ");
			i++;
		}
	}
	if (newline == 1)
		ft_printf("\n");
	env_add("?=0", sh->env);
}

void	cd(int ac, char **av, t_minishell *sh)
{
	int		exit;

	exit = 0;
	if (ac == 1)
	{
		if (chdir(get_env(sh, "HOME")))
		{
			put_error(strerror(errno));
			exit = 1;
		}
	}
	else if (ac > 2)
	{
		put_error("Too many arguments");
		exit = 1;
	}
	else if (chdir(av[1]))
	{
		put_error(strerror(errno));
		exit = 1;
	}
	if (exit == 1)
		env_add("?=1", sh->env);
	else
		env_add("?=0", sh->env);
}

void	pwd(t_minishell *sh)
{
	char	path[1024];

	if (!getcwd(path, 1024))
	{
		put_error(strerror(errno));
		env_add("?=1", sh->env);
	}
	else
	{
		ft_printf("%s\n", (path));
		env_add("?=0", sh->env);
	}
}
