/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 15:04:12 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 17:18:28 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int		parse_quote_check(t_minishell *sh, int i, int j, int x)
{
	char	*tmp;

	sh->data[i][j] = x;
	tmp = ft_strtrim(sh->args[i][j], 1);
	if (!tmp)
	{
		put_error(strerror(errno));
		return (0);
	}
	free(sh->args[i][j]);
	sh->args[i][j] = tmp;
	return (1);
}

int		parse_single_quote(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (is_single_quote(sh->args[i][j]))
			{
				if (!parse_quote_check(sh, i, j, 1))
					return (0);
			}
			else
				sh->data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		parse_double_quote(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (is_double_quote(sh->args[i][j]))
			{
				if (!parse_quote_check(sh, i, j, 2))
					return (0);
			}
			else if (sh->data[i][j] != 1)
				sh->data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		parse_quotes(t_minishell *sh)
{
	sh->data = allocate_data(sh->line_count, sh->arg_count);
	if (!sh->data)
		return (0);
	if (!parse_single_quote(sh))
		return (0);
	if (!parse_double_quote(sh))
		return (0);
	return (1);
}
