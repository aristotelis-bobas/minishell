/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   troubleshoot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 13:41:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 17:06:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		show_args(t_minishell *sh)
{
	int i;
	
	i = 0;
	while (i < sh->arg_count)
	{
		if (sh->args[i] != 0)
			printf("argument[%d] = \"%s\"\n", i, sh->args[i]);
		i++;
	}
}
