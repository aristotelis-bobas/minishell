/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 16:16:35 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 16:28:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     check_literal(char *arg)
{
	if (arg[0] == 39 && arg[ft_strlen(arg) - 1] == 39)
		return (1);
	return (0);
}

int     check_semi(char *arg)
{
	if (arg[0] == 34 && arg[ft_strlen(arg) - 1] == 34)
		return (1);
	return (0);
}

void	init_bool(t_minishell *sh)
{
	int		i;

	sh->bool = (int*)malloc(sizeof (int) * sh->arg_count);
	if (sh->bool == 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < sh->arg_count)
	{
		sh->bool[i] = 0;
		i++;
	}
}

void    parse_quotes(t_minishell *sh)
{
	int     i;
	
	i = 0;
	while (i < sh->arg_count)
	{
		if (check_literal(sh->args[i]))
		{
			sh->bool[i] = 1;
			sh->args[i] = ft_trim(sh->args[i]);
		}
		else if (check_semi(sh->args[i]))
		{
			sh->bool[i] = 2;
			sh->args[i] = ft_trim(sh->args[i]);
		}
		i++;
	}
}

void    parse_input(t_minishell *sh)
{
	init_bool(sh);
	parse_quotes(sh);
	parse_env(sh);
	prep_args(sh);
}
