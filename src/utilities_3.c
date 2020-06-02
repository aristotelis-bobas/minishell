/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 18:07:34 by abobas        ########   odam.nl         */
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

int		expand_length_loop(t_minishell *sh, char *src, int start, int i)
{
	char	*var;
	char	*env;
	int		length;

	var = ft_substr(src, start, i - start);
	if (!var)
	{
		put_error(strerror(errno));
		return (-1);
	}
	env = get_env(sh, var);
	free(var);
	length = ft_strlen(env);
	if (env)
		free(env);
	return (length);
}

int		expand_length(t_minishell *sh, char *src)
{
	int		i;
	int		length;
	int		start;
	int		tmp;

	i = 0;
	length = 0;
	while (src[i] != '\0')
	{
		i++;
		if (src[i - 1] == '$' && is_var_char(src[i]))
		{
			start = i;
			while (is_var_char(src[i]))
				i++;
			tmp = expand_length_loop(sh, src, start, i);
			if (tmp == -1)
				return (0);
			length += tmp;
		}
		else
			length++;
	}
	return (length);
}

int		vector_search_env(t_vector *v, char *reference)
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

char	*get_env(t_minishell *sh, char *env)
{
	char	*tmp;

	tmp = vector_get(sh->env, vector_search_env(sh->env, env));
	if (!tmp)
		return (0);
	tmp = ft_substr(tmp, ft_strlen(env) + 1, ft_strlen(tmp) - ft_strlen(env));
	if (!tmp)
	{
		put_error(strerror(errno));
		return (0);
	}
	return (tmp);
}
