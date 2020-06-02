/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 23:45:04 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 15:53:01 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		parse_expand_loop(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (is_var(sh->args[i][j]) > 0 && sh->data[i][j] != 1)
			{
				sh->args[i][j] = expand_var(sh, sh->args[i][j]);
				if (!sh->args[i][j])
					return (0);
				if (ft_strlen(sh->args[i][j]) == 0 && sh->data[i][j] == 0)
				{
					free(sh->args[i][j]);
					sh->args[i][j] = 0;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	parse_quote_rmpcpy(t_minishell *sh, int i, int j, char *tmp)
{
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (tmp[c])
	{
		if (tmp[c] == '"' && sh->data[i][j] == 1)
		{
			sh->args[i][j][d] = tmp[c];
			d++;
		}
		if (!(tmp[c] == '$' && (tmp[c + 1] == '"' || tmp[c + 1] == '\'')))
			if (tmp[c] != '"' && tmp[c] != '\'')
			{
				sh->args[i][j][d] = tmp[c];
				d++;
			}
		c++;
	}
	sh->args[i][j][d] = '\0';
	free(tmp);
}

int		parse_quote_new(t_minishell *sh, int i, int j)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup(sh->args[i][j]);
	if (!tmp)
	{
		put_error(strerror(errno));
		return (0);
	}
	free(sh->args[i][j]);
	len = ft_strlen(tmp) - parse_quote_count(sh->args[i][j], sh->data[i][j]);
	sh->args[i][j] = (char*)malloc(sizeof(char) * len + 1);
	if (!sh->args[i][j])
	{
		free(tmp);
		put_error(strerror(errno));
		return (0);
	}
	parse_quote_rmpcpy(sh, i, j, tmp);
	return (1);
}

int		parse_quote_rm(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (parse_quote_count(sh->args[i][j], sh->data[i][j]))
				if (!parse_quote_new(sh, i, j))
				{
					put_error(strerror(errno));
					return (0);
				}
			j++;
		}
		i++;
	}
	return (1);
}

int		parse_expand(t_minishell *sh)
{
	if (!parse_expand_home(sh))
		return (0);
	if (!parse_expand_loop(sh))
		return (0);
	if (!parse_sanitize(sh))
		return (0);
	if (!parse_quote_rm(sh))
		return (0);
	return (1);
}
