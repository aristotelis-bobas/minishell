/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:49:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 19:57:43 by abobas        ########   odam.nl         */
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
	home = get_env(sh, "HOME");
	if (!home)
		return (0);
	return (shorten_dir(home, path));
}

char	*save_prompt(char *user, char *dir)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (j < ft_strlen(user))
	{
		g_prompt[i] = user[j];
		i++;
		j++;
	}
	g_prompt[i] = ':';
	i++;
	j = 0;
	while (j < ft_strlen(dir))
	{
		g_prompt[i] = dir[j];
		i++;
		j++;
	}
	g_prompt[i] = '$';
	g_prompt[i + 1] = ' ';
	g_prompt[i + 2] = '\0';
	return (g_prompt);
}

int		prompt(t_minishell *sh)
{
	char	*dir;
	char	*user;
	char	ret;
	int		length;

	ret = 0;
	user = get_env(sh, "USER");
	dir = get_dir(sh);
	if (user && dir)
	{
		length = ft_strlen(user) + ft_strlen(dir) + 3;
		g_prompt = (char*)malloc(sizeof(char) * length + 1);
		if (!g_prompt)
			put_error(strerror(errno));
		else
		{
			ft_printf("%s", save_prompt(user, dir));
			ret = 1;
		}
	}
	if (dir)
		free(dir);
	if (user)
		free(user);
	return (ret);
}
