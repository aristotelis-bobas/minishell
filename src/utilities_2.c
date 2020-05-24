/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:45:43 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 01:51:28 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	free_file_descriptors(t_minishell *sh, int line_count)
{
	int		y;

	y = 0;
	while (y < line_count)
	{
		if (sh->file_descriptors[y])
			free(sh->file_descriptors[y]);
		y++;
	}
	free(sh->file_descriptors);
}

int		allocate_file_descriptors(t_minishell *sh)
{
	int 	i;

	i = 0;
	sh->file_descriptors = (int**)malloc(sizeof(int*) * sh->line_count);
	if (!sh->file_descriptors)
		return (0);
	while (i < sh->line_count)
	{
		sh->file_descriptors[i] = (int*)malloc(sizeof(int) * 4);
		if (!sh->file_descriptors[i])
		{
			free_file_descriptors(sh, i);
			return (0);
		}
		sh->file_descriptors[i][0] = 0;
		sh->file_descriptors[i][1] = 0;
		sh->file_descriptors[i][2] = 0;
		sh->file_descriptors[i][3] = 0;
		i++;
	}
	return (1);
}