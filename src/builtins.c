/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:44:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/18 01:37:05 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

void	echo(int ac, char **av)
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
}

void	cd(int ac, char **av, t_minishell *sh)
{
	if (ac == 1)
	{
		if (chdir(get_env(sh, "HOME")))
			put_error(strerror(errno));
	}
	else if (ac > 2)
		put_error("Too many arguments");
	else if (chdir(av[1]))
		put_error(strerror(errno));
}

void	pwd(void)
{
	char	path[1024];

	if (!getcwd(path, 1024))
		put_error(strerror(errno));
	else
		ft_printf("%s\n", (path));
}
