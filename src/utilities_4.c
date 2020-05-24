/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/23 15:14:05 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		is_var(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && is_var_char(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int		is_var_char(char c)
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

int		is_double_quote(char *str)
{
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}

int		is_single_quote(char *str)
{
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
}
