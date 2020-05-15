/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 16:59:25 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 16:28:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         check_env(char *arg)
{
	int     i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 36)
			return (i + 1);
		i++;
	}
	return (0);
}

void        substitute_env(t_minishell *sh, int i, int start)
{
	char    *env;
	char    *result;
	char    *temp;

	env = ft_substr(sh->args[i], start, ft_strlen(sh->args[i]) - start);
	result = get_env(sh, env);
	free(env);
	temp = ft_substr(sh->args[i], 0, start -1);
	free(sh->args[i]);
	if (sh->bool[i] == 2 && !result)
		result = ft_strdup("");
	if (sh->bool[i] == 0 && !ft_strlen(temp) && !result)
		sh->args[i] = 0;
	else
		sh->args[i] = ft_strjoin(temp, result);
	if (result)
		free(result);
	free(temp);
}

void        parse_env(t_minishell *sh)
{
	int     i;
	int     start;

	i = 0;
	while (i < sh->arg_count)
	{
		if ((start = check_env(sh->args[i])) > 0 && sh->bool[i] != 1)
			substitute_env(sh, i, start);
		i++;
	}
}