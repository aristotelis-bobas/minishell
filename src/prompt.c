/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:49:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 20:28:24 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_host(void)
{
	int		fd;
	char	*host;

	if ((fd = open("/proc/sys/kernel/hostname", O_RDONLY)) < 0)
	{
		put_error(strerror(errno));
		return (0);
	}
	if (!(host = ft_readline(fd, 64)))
	{
		put_error("Reading hostname has failed");
		return (0);
	}	
	close(fd);
	return (host);
}

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
	{
		put_error("Retrieving 'HOME' environment variable has failed");
		return (0);
	}
	return (shorten_dir(home, path));
}

int		prompt(t_minishell *sh)
{
	char	*host;
	char	*dir;
	char	*user;
	char	ret;

	ret = 0;
	user = get_env(sh, "USERNAME");
	host = get_host();
	dir = get_dir(sh);
	if (user && host && dir)
	{
		ft_printf("%s@%s:%s$ ", user, host, dir);
		ret = 1;
	}
	if (host)
		free(host);
	if (dir)
		free(dir);
	if (user)
		free(user);
	return (ret);
}
