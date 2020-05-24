/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 14:10:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 01:48:55 by abobas        ########   odam.nl         */
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
	sh->data = 0;
	if (sh->arg_count)
		free(sh->arg_count);
	sh->arg_count = 0;
	if (sh->file_descriptors)
		free_file_descriptors(sh, sh->line_count);
	sh->file_descriptors = 0;
	sh->line_count = 0;
}
