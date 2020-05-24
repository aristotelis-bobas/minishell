/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_split.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 20:44:49 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/23 14:33:24 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

int				traverse_word(t_minishell *sh, int i)
{
	int		count;
	int		quote;
	int		start;

	count = 0;
	quote = 0;
	start = i;
	while (sh->line[i] != '\0')
	{
		if (is_space(sh->line[i]) && !(count % 2))
			break ;
		if (is_redirect(sh->line[i]))
			start++;
		if (is_redirect(sh->line[i]) && i > start && !(count % 2))
			break ;
		if (is_redirect(sh->line[i]) && !is_redirect(sh->line[i + 1]) && !(count % 2))
		{
			i++;
			break ;
		}
		if (sh->line[i] == ';' && !(count % 2))
			break ;
		if ((sh->line[i] == '\'' || sh->line[i] == '"') && !quote)
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

static void		count_lines(t_minishell *sh)
{
	int		i;

	i = 0;
	sh->line_count = 1;
	while (sh->line[i] != '\0')
	{
		if (is_space(sh->line[i]) || is_redirect(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			sh->line_count++;
			i++;
		}
		else
			i = traverse_word(sh, i);
	}
}

static void		count_args(t_minishell *sh)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	sh->arg_count[y] = 0;
	while (sh->line[i] != '\0')
	{
		if (is_space(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			y++;
			sh->arg_count[y] = 0;
			i++;
		}
		else if (is_redirect(sh->line[i]))
		{
			if (!is_redirect(sh->line[i + 1]))
				sh->arg_count[y]++;
			i++;
		}
		else
		{
			i = traverse_word(sh, i);
			sh->arg_count[y]++;
		}
	}
}

int				split(t_minishell *sh)
{
	int		i;
	int		x;
	int		y;
	int		start;

	i = 0;
	x = 0;
	y = 0;
	while (sh->line[i] != '\0')
	{
		if (is_space(sh->line[i]))
			i++;
		else if (sh->line[i] == ';')
		{
			x++;
			y = 0;
			i++;
		}
		else
		{
			start = i;
			i = traverse_word(sh, i);
			if (!(sh->args[x][y] = ft_substr(sh->line, start, i - start)))
			{
				put_error(strerror(errno));
				return (0);
			}
			y++;
		}
	}
	return (1);
}

int				parse_split(t_minishell *sh)
{
	count_lines(sh);
	if (!(sh->arg_count = allocate_counter(sh->line_count)))
		return (0);
	count_args(sh);
	if (!(sh->args = allocate_array(sh->line_count, sh->arg_count)))
		return (0);
	if (!split(sh))
		return (0);
	if (!parse_sanitize(sh))
		return (0);
	return (1);
}
