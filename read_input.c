/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:55:19 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/15 17:44:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_loop(t_minishell *sh)
{
	int		bufsize;
	int		i;
	char	ch;

	bufsize = 1024;
	i = 0;
	while (1)
	{
		if (read(0, &ch, 1) < 0)
			exit(EXIT_FAILURE);
		if (ch == '\n')
		{
			sh->line[i] = '\0';
			return ;
		}
		else
			sh->line[i] = ch;
		i++;
		if (i == bufsize)
		{
			bufsize += 1024;
			sh->line = ft_reallocate(sh->line, bufsize - 1024, bufsize);
		}
	}
}

void	read_input(t_minishell *sh)
{
	sh->line = (char*)malloc(sizeof(char) * 1024);
	if (!sh->line)
		exit(EXIT_FAILURE);
	read_loop(sh);
}
