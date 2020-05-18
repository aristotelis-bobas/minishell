/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 20:08:19 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		is_var(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && is_varchar(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int		is_varchar(char c)
{
	return (c != ';' && c != '$' && c != '\'' && !is_space(c) && c);
}

int		is_env(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		is_literal(char *str)
{
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
}

int		is_semi(char *str)
{
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}
