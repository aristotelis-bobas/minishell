/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:49:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/18 22:25:25 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

char	*shorten_dir(char *home, char *path)
{
	char	*tmp;
	char	*dir;
	
	if (!ft_strncmp(home, path, ft_strlen(home)))
	{
		tmp = ft_substr(path, ft_strlen(home), ft_strlen(path));
		free(home);
		if (!tmp)
		{
			put_error(strerror(errno));
			return (0);
		}
		dir = ft_strjoin("~", tmp);
		free(tmp);
		if (!dir)
			put_error(strerror(errno));
		return (dir);
	}
	free(home);
	dir = ft_strdup(path);
	if (!dir)
		put_error(strerror(errno));
	return (dir);
}

char	*get_dir(t_minishell *sh)
{
	char	path[1024];
	char	*home;

	if (!(getcwd(path, 1024)))
	{
		put_error(strerror(errno));
		return (0);
	}
	if (!(home = get_env(sh, "HOME")))
		return (0);
	return (shorten_dir(home, path));
}

int		prompt(t_minishell *sh)
{
	char	*dir;
	char	*user;
	char	ret;

	ret = 0;
	user = get_env(sh, "USER");
	dir = get_dir(sh);
	if (user && dir)
	{
		ft_printf("%s:%s$ ", user, dir);
		ret = 1;
	}
	if (dir)
		free(dir);
	if (user)
		free(user);
	return (ret);
}
