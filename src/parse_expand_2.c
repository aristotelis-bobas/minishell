/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 12:27:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/28 12:28:17 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		expand_error(char *dst)
{
	put_error(strerror(errno));
	free(dst);
	return (-1);
}

int		expand(int j, char *dst, char *env, t_minishell *sh)
{
	int		i;
	char	*src;

	if (!env)
		return (expand_error(dst));
	if (env[0] == '$')
	{
		src = ft_strdup(env);
		if (!src)
			return (expand_error(dst));
	}
	else
		src = get_env(sh, env);
	free(env);
	i = 0;
	if (src)
		while (src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	if (src)
		free(src);
	return (j);
}

int		expand_start_check(int start, char *src, int i)
{
	if (start > 1)
		if (src[i] == '\'' && src[start - 2] == '\'')
			start--;
	return (start);
}

char	*expand_arg(t_minishell *sh, char *dst, char *src, int i)
{
	int		j;
	int		start;

	j = 0;
	while (src[i] != '\0')
	{
		i++;
		if (src[i - 1] == '$' && is_var_char(src[i]))
		{
			start = i;
			while (is_var_char(src[i]))
				i++;
			start = expand_start_check(start, src, i);
			j = expand(j, dst, ft_substr(src, start, i - start), sh);
			if (j < 0)
				return (0);
		}
		else
		{
			dst[j] = src[i - 1];
			j++;
		}
	}
	dst[j] = '\0';
	return (dst);
}

char	*expand_var(t_minishell *sh, char *src)
{
	char	*dst;
	int		length;
	int		i;

	length = expand_length(sh, src);
	if (length < 0)
		return (0);
	dst = (char*)malloc(sizeof(char) * length + 1);
	if (!dst)
	{
		free(src);
		put_error(strerror(errno));
		return (0);
	}
	i = 0;
	dst = expand_arg(sh, dst, src, i);
	free(src);
	return (dst);
}
