/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_redirect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:51:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 02:16:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int		parse_output_redirect(t_minishell *sh, int i, int y)
{
	int		fd;

	if (sh->file_descriptors[i][0] != 0)
		close(sh->file_descriptors[i][1]);
	sh->file_descriptors[i][0] = 1;
	if (!ft_strcmp(sh->args[i][y], ">>"))
		fd = open(sh->args[i][y + 1], (O_CREAT | O_WRONLY |O_APPEND), 0666);
	else
		fd = open(sh->args[i][y + 1], (O_CREAT | O_WRONLY), 0666);
	if (fd < 0)
	{
		put_error(strerror(errno));
		return (0);
	}
	sh->file_descriptors[i][1] = fd;
	sh->args[i][y] = 0;
	sh->args[i][y + 1] = 0;
	return (1);
}

int		parse_input_redirect(t_minishell *sh, int i, int y)
{
	int		fd;

	if (sh->file_descriptors[i][2] != 0)
		close(sh->file_descriptors[i][3]);
	sh->file_descriptors[i][2] = 1;
	fd = open(sh->args[i][y + 1], O_RDONLY);
	if (fd < 0)
	{
		put_error(strerror(errno));
		return (0);
	}
	sh->file_descriptors[i][3] = fd;
	sh->args[i][y] = 0;
	sh->args[i][y + 1] = 0;
	return (1);
}

int		parse_redirection(t_minishell *sh, int i, int y)
{
	if (!ft_strcmp(sh->args[i][y], ">>") || !ft_strcmp(sh->args[i][y], ">"))
	{
		if (!parse_output_redirect(sh, i, y))
			return (0);
	}
	else if (!ft_strcmp(sh->args[i][y], "<"))
	{
		if (!parse_input_redirect(sh, i, y))
			return (0);
	}
	return (1);
}

int		parse_redirections(t_minishell *sh)
{
	int		i;
	int		y;

	i = 0;
	while (i < sh->line_count)
	{
		y = 0;
		while (y < sh->arg_count[i])
		{
			if (sh->args[i][y])
			{
				if (is_redirect(sh->args[i][y][0]) && !sh->data[i][y])
				{
					if (!parse_redirection(sh, i, y))
						return (0);
				}
			}
			y++;
		}
		i++;
	}
	return (1);
}

int		parse_redirect(t_minishell *sh)
{
	if (!allocate_file_descriptors(sh))
		return (0);
	if (!parse_redirections(sh))
		return (0);
	if (!parse_sanitize(sh))
		return (0);
	return (1);
}