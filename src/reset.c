/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 14:10:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 15:22:12 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>

void    reset(t_minishell *sh)
{
	if (sh->line)
		free(sh->line);
	sh->line = 0;
	if (sh->args)
		free_array(sh->args, sh->line_count, sh->arg_count);
	sh->args = 0;
	if (sh->data)
		free_data(sh->data, sh->line_count);
	if (sh->arg_count)
		free(sh->arg_count);
	sh->arg_count = 0;
	sh->line_count = 0;
}
