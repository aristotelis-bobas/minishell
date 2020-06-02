/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_6.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/24 16:19:41 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/26 14:07:31 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>

int		trav_word_util(t_minishell *sh, int i, int count, int start)
{
	if (is_redirect(sh->line[i]) && i > start && !(count % 2))
		return (i);
	if ((is_redirect(sh->line[i]) && !is_redirect(sh->line[i + 1])) || \
	sh->line[i] == '|')
	{
		if (!(count % 2))
			return (i + 1);
	}
	if (sh->line[i] == ';' && !(count % 2))
		return (i);
	return (-1);
}

int		split_sub(t_minishell *sh, int i, int x, int y)
{
	int		start;

	start = i;
	i = traverse_word(sh, i);
	sh->args[x][y] = ft_substr(sh->line, start, i - start);
	if (!sh->args[x][y])
	{
		put_error(strerror(errno));
		return (-1);
	}
	return (i);
}

int		count_args_helper(t_minishell *sh, int i, int y)
{
	i = traverse_word(sh, i);
	sh->arg_count[y]++;
	return (i);
}

int		sanitize_data(t_minishell *sh, int lc, int *ac)
{
	int		**data;

	if (sh->data)
	{
		data = allocate_data(lc, ac);
		if (!data)
			return (0);
		data = fill_data(data, sh);
		free_data(sh->data, sh->line_count);
		sh->data = data;
	}
	return (1);
}

int		array_helper(t_minishell *sh, char ***arr, int i, int x)
{
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < sh->arg_count[i])
	{
		if (sh->args[i][y] != 0)
		{
			arr[x][z] = ft_strdup(sh->args[i][y]);
			if (!arr[x][z])
				return (0);
			z++;
		}
		y++;
	}
	return (1);
}
