/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 18:13:02 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	env_show(t_minishell *sh)
{
	vector_print(sh->env);
	env_add("?=0", sh->env);
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
	char	*delete;

	delete = get_identifier(reference);
	env_delete(delete, v);
	if (delete)
		free(delete);
	insert = ft_strdup(reference);
	if (!insert)
		put_error(strerror(errno));
	else
	{
		if (!vector_add(v, insert))
			put_error(strerror(errno));
	}
}

void	unset(int ac, char **av, t_minishell *sh)
{
	int		i;
	int		exit;

	i = 1;
	exit = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_env(av[i]) || !ft_strcmp(av[i], "?"))
			{
				put_error("Not a valid identifier");
				exit = 1;
			}
			else
				env_delete(av[i], sh->env);
			i++;
		}
	}
	if (exit == 1)
		env_add("?=1", sh->env);
	else
		env_add("?=0", sh->env);
}
