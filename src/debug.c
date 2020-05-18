/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 13:41:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 01:53:07 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		show_args(t_minishell *sh)
{
	int     x;
	int		y;

	x = 0;
	while (x < sh->line_count)
	{
		y = 0;
		while (y < sh->arg_count[x])
		{
			if (sh->args[x][y])
				ft_printf("arg[%d][%d] = \"%s\"\n", x, y, sh->args[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

void		show_linecount(t_minishell *sh)
{
	ft_printf("line_count = %d\n", sh->line_count);
}

void		show_argcount(t_minishell *sh)
{
	int		i;

	i = 0;
	while (i < sh->line_count)
	{
		ft_printf("arg_count[%d] = %d\n", i, sh->arg_count[i]);
		i++;
	}
}

void		show_data(t_minishell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (i < sh->line_count)
	{
		j = 0;
		while (j < sh->arg_count[i])
		{
			ft_printf("data[%d][%d] = %d\n", i, j, sh->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void		debug(t_minishell *sh)
{
	ft_printf("\n========================DEBUGGER========================\n");
	show_linecount(sh);
	ft_printf("\n");
	show_argcount(sh);
	ft_printf("\n");
	if (sh->args)
		show_args(sh);
	if (sh->data)
		show_data(sh);
	ft_printf("========================================================\n\n");
}