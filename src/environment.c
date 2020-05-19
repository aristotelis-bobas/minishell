/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/19 02:30:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

void		export(int ac, char **av, t_minishell *sh)
{
	int		i;
	
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
				env_add(av[i], sh->env);
			i++;
		}
	}
}

void	env_delete(char *reference, t_vector *v)
{
	int		delete;

	delete = vector_search_env(v, reference);
	if (delete > 0)
		vector_delete(v, delete);
}

void	env_add(char *reference, t_vector *v)
{
	char	*insert;
	
	if (!(insert = ft_strdup(reference)))
		put_error(strerror(errno));
	else
		vector_add(v, insert);
}

void	unset(int ac, char **av, t_minishell *sh)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]))
				put_error("Not a valid identifier");
			env_delete(av[i], sh->env);
			i++;
		}
	}
}
