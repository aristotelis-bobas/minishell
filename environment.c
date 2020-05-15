/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/14 21:50:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        *get_env(t_minishell *sh, char *env)
{
	t_env   *list;
	int     length;
	int     start;

	list = sh->first_element;
	start = ft_strlen(env) + 1;
	length = ft_strlen(list->data) - start;
	while (list)
	{
		if (!ft_envcmp(list->data, env))
			return (ft_substr(list->data, start, length));
		list = list->next;
	}
	return (0);
}

void        env_show(t_minishell *sh)
{
	t_env *list;

	list = sh->first_element;
	while (list)
	{
		if (list->data)
			ft_putendl(list->data);
		list = list->next;
	}
}

void        env_export(t_minishell *sh)
{
	char    *insert;
	int     i;

	i = 0;
	insert = ft_strdup(sh->args[sh->arg_index + 1]);
	list_remove_if(&sh->first_element, insert);
	while (insert[i] != '\0')
	{
		if (insert[i] == '=')
		{
			list_push_back(&sh->first_element, insert);
			return ;
		}
		i++;
	}
}

void    env_unset(t_minishell *sh)
{
	char    *data_ref;

	data_ref = sh->args[sh->arg_index + 1];
	list_remove_if(&sh->first_element, data_ref);
}
