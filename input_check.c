/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 17:11:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 17:31:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int		input_check(t_minishell *sh)
{
	int		i;

	i = 0;

	while (i < sh->arg_count)
	{
		if (!quote_check(sh->args[i]))
		{
			free(sh->line);
			free_args(sh);
			ft_error("Missing quotes");
			return (0);
		}
		i++;
	}
	return (1);
}
