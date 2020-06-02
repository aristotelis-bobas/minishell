/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand_3.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 15:54:30 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/29 16:06:29 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>

int		parse_expand_home(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			if (!(ft_strcmp(sh->args[i][j], "~")) && !sh->data[i][j])
			{
				free(sh->args[i][j]);
				sh->args[i][j] = get_env(sh, "HOME");
				if (!sh->args[i][j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
