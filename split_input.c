/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:28:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/15 17:54:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		word_loop(t_minishell *sh, int i)
{
	int		count;
	int		quote;

	count = 0;
	quote = 0;
	while (sh->line[i] != '\0')
	{
		if (ft_isspace(sh->line[i]) && !(count % 2))
			break;
		if (sh->line[i] == ';' && !quote)
			break ;
		if ((sh->line[i] == 34 || sh->line[i] == 39) && !quote)
		{
			quote = sh->line[i];
			count++;
		}
		else if (sh->line[i] == quote)
			count++;
		i++;
	}
	return (i);
}

void	count(t_minishell *sh)
{
	int		i;

	i = 0;
	sh->arg_count = 0;
	while (sh->line[i] != '\0')
	{
		if (ft_isspace(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			sh->arg_count++;
			i++;
		}
		else
		{
			i = word_loop(sh, i);
			sh->arg_count++;
		}
	}
}

void	split(t_minishell *sh)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	if (sh->line[i] == '\0')
	{
		sh->args[j] = ft_strdup("");
		return ;
	}
	while (sh->line[i] != '\0')
	{
		if (ft_isspace(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			sh->args[j] = ft_strdup(";");
			j++;
			i++;
		}
		else
		{
			start = i;
			i = word_loop(sh, i);
			sh->args[j] = ft_substr(sh->line, start, i - start);
			j++;
		}
	}
	sh->args[j] = 0;
}

void	split_input(t_minishell *sh)
{
	count(sh);
	sh->args = (char**)malloc(sizeof(char *) * sh->arg_count + 1);
	if (sh->args == 0)
		exit(EXIT_FAILURE);
	split(sh);
}
