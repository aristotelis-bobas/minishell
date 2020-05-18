/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 20:10:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

void		export(int ac, char **av, t_minishell *sh)
{
	int		i;
	char	*insert;
	
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
			{
				if (!(insert = ft_strdup(av[i])))
					put_error(strerror(errno));
				else
					vector_add(sh->env, insert);
			}
			i++;
		}
	}
}

void	unset(int ac, char **av, t_minishell *sh)
{
	int		delete;
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
				put_error("Not a valid identifier");
			delete = vector_search_env(sh->env, av[i]);
			if (delete > 0)
				vector_delete(sh->env, delete);
			i++;
		}
	}
}
