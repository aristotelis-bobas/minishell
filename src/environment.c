/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 23:36:55 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			vector_search_env(t_vector *v, char *reference)
{
	int		index;

	index = 0;
	while (index < v->total)
	{
		if (!env_cmp(reference, v->data[index]))
			return (index);
		index++;
	}
	return (0);
}

char		*get_env(t_minishell *sh, char *env)
{
	char	*tmp;
	
	if (!(tmp = vector_get(sh->env, vector_search_env(sh->env, env))))
		return (0);
	return (ft_substr(tmp, ft_strlen(env) + 1, ft_strlen(tmp) - ft_strlen(env)));
}