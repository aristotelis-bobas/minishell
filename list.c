/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:55 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/14 21:50:21 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_element(char *data)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
	{
		exit(EXIT_FAILURE);
	}
	new->data = data;
	new->next = 0;
	return (new);
}

void	list_push_back(t_env **first_element, char *data)
{
	t_env *list;

	list = *first_element;
	while (list->next)
		list = list->next;
	list->next = create_element(data);
}

void	list_remove_if(t_env **first_element, char *ref_data)
{
	t_env   *list;
	t_env   *next_element;

	list = *first_element;
	while (list)
	{
		if (list->next)
		{
			next_element = list->next;
			if (!ft_envcmp(next_element->data, ref_data))
			{
				if (next_element->next)
					list->next = next_element->next;
				else
					list->next = 0;
				free(next_element);
				return ;
			}
		}
		list = list->next;
	}
}

void    setup_list(t_minishell *sh, char **env)
{
	int     i;
	t_env   *begin;

	begin = create_element(env[0]);
	i = 1;
	while (env[i] != 0)
	{
		list_push_back(&begin, env[i]);
		i++;
	}
	sh->first_element = begin;
}