/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 17:11:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 12:42:47 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		quote_check(char *arg)
{
	int		i;
	int		quote;
	int		count;

	i = 0;
	quote = 0;
	count = 0;
	while (arg[i])
	{
		if (!quote && (arg[i] == '\'' || arg[i] == '"'))
		{
			quote = arg[i];
			count = 1;
		}
		else if (arg[i] == quote)
			count++;
		if (count == 2)
			quote = 0;
		i++;
	}
	if (count % 2)
		return (0);
	return (1);
}

int		redirect_check(t_minishell *sh, int i, int y)
{
	char	*arg;
	char	*arg_2;

	arg = sh->args[i][y];
	if (sh->data)
	{
		if (is_redirect(arg[0]) && sh->data[i][y] != 0)
			return (1);
	}
	if (is_redirect(arg[0]) && y + 1 == sh->arg_count[i])
		return (0);
	arg_2 = sh->args[i][y + 1];
	if (is_redirect(arg[0]) && is_redirect(arg_2[0]))
		return (0);
	if (is_redirect(arg[0]) && is_pipe(arg_2[0]))
		return (0);
	if (arg[0] == '>' && ft_strlen(arg) > 2)
		return (0);
	if (arg[0] == '>' && arg[1] != '\0' && arg[1] != '>')
		return (0);
	if (arg[0] == '<' && ft_strlen(arg) > 1)
		return (0);
	return (1);
}

int		pipe_check(t_minishell *sh, int i, int y)
{
	char	*arg;
	char	*arg_2;

	arg = sh->args[i][y];
	if (is_pipe(arg[0]) && y + 1 == sh->arg_count[i])
		return (0);
	arg_2 = sh->args[i][y + 1];
	if (is_pipe(arg[0]) && is_redirect(arg_2[0]))
		return (0);
	if (is_pipe(arg[0]) && ft_strlen(arg) > 1)
		return (0);
	return (1);
}

int		parse_validate(t_minishell *sh)
{
	int		i;
	int		y;

	i = 0;
	while (i < sh->line_count)
	{
		y = 0;
		while (y < sh->arg_count[i])
		{
			if (!quote_check(sh->args[i][y]) && !sh->data)
			{
				put_error("Missing quotes");
				return (0);
			}
			if (!redirect_check(sh, i, y) || !pipe_check(sh, i, y))
			{
				put_error("Syntax error");
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}
