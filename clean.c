/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 14:10:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 17:32:04 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_args(t_minishell *sh)
{
	int     i;

	i = 0;
	while (i < sh->arg_count)
	{
		if (sh->args[i])
			free(sh->args[i]);
		i++;
	}
	free(sh->args);
}

void    clean(t_minishell *sh)
{
	free(sh->line);
	free_args(sh);
	free(sh->bool);
}