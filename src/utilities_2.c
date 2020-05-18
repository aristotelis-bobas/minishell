/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 20:13:14 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		env_cmp(char *reference, char *data)
{
	int		i;

	i = 0;
	if (!reference || !data)
		return (1);
	while (reference[i] != '\0' && data[i] != '\0')
	{
		if (reference[i] != data[i])
			return (1);
		i++;
	}
	if (reference[i] == '\0' && data[i] == '=')
		return (0);
	else
		return (1);
}

int		expand_length(t_minishell *sh, char *src)
{
	int		i;
	int		length;
	int		start;
	char	*var;
	char	*env;

	i = 0;
	length = 0;
	while (src[i] != '\0')
	{
		i++;
		if (src[i - 1] == '$' && is_varchar(src[i]))
		{
			start = i;
			while (is_varchar(src[i]))
				i++;
			if (!(var = ft_substr(src, start, i - start)))
				return (-1);
			env = get_env(sh, var);
			free(var);
			length += ft_strlen(env);
			if (env)
				free(env);
		}
		else
			length++;
	}
	return (length);
}

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
	return (-1);
}

char		*get_env(t_minishell *sh, char *env)
{
	char	*tmp;
	
	if (!(tmp = vector_get(sh->env, vector_search_env(sh->env, env))))
		return (0);
	if (!(tmp = ft_substr(tmp, ft_strlen(env) + 1, ft_strlen(tmp) - ft_strlen(env))))
	{
		put_error(strerror(errno));
		return (0);
	}
	return (tmp);
}
