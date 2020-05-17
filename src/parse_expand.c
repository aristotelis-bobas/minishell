/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 23:45:04 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 23:57:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		parse_expand(t_minishell *sh)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			//// IF VARIABLES IN ARG >> EXPAND VARIABLES
			//// IF ERROR >> RETURN (0)
			j++;
		}
		i++;
	}
	if (!parse_sanitize(sh)) ///// HAALT ALLE ARGUMENTS NULL-POINTER ZIJN ER TUSSEN UIT
		return (0);
	return (1);
}