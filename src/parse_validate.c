/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 17:11:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 04:48:31 by abobas        ########   odam.nl         */
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
		if (!quote && (arg[i] == 34 || arg[i] == 39))
		{
			quote = arg[i];
			count = 1;
		}
		else if (arg[i] == quote)
			count++;
		i++;
	}
	if (count % 2)
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
			if (!quote_check(sh->args[i][y]))
			{
				put_error("Missing quotes");
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}
