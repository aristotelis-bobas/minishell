/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_read.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 20:29:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 00:56:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

int		parse_read(t_minishell *sh)
{
	sh->line = ft_readline(0, 128);
	if (!sh->line)
	{
		put_error(strerror(errno));
		return (0);
	}
	if (sh->line[0] == '\0')
		return (0);
	return (1);
}