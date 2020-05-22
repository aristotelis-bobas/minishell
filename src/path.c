/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 13:10:17 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 19:45:36 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


void			free_path_array(char **path_array)
{
	int			i;

	i = 0;
	while (path_array[i] != 0)
	{
		if (path_array[i])
			free(path_array[i]);
		i++;
	}
	free(path_array);
}

char			*make_executable(char *bin, char *arg)
{
	char	*new_bin;
	char	*new_executable;

	if (!(new_bin = ft_strjoin(bin, "/")))
	{
		free(arg);
		put_error(strerror(errno));
		return (0);
	}
	new_executable = ft_strjoin(new_bin, arg);
	free(new_bin);
	free(arg);
	if (!new_executable)
	{
		put_error(strerror(errno));
		return (0);
	}
	return (new_executable);
}

int				scan_directory(char *bin, char *arg)
{
	DIR					*dir;
	struct dirent		*dirent;

	
	if (!(dir = opendir(bin)))
	{
		put_error(strerror(errno));
		return (0);
	}
	errno = 0;
	while ((dirent = readdir(dir)) != 0)
	{
		if (!ft_strcmp(dirent->d_name, arg))
		{
			closedir(dir);
			return (1);
		}
	}
	if (errno > 0)
		put_error(strerror(errno));
	closedir(dir);
	return (0);
}

char			*find_executable(char *arg, char **path_array)
{
	int		i;

	i = 0;
	while (path_array[i] != 0)
	{
		if (scan_directory(path_array[i], arg))
		{
			arg = make_executable(path_array[i], arg);
			break ;
		}
		i++;
	}
	free_path_array(path_array);
	return (arg);
}

char			*get_executable(char *arg, t_minishell *sh)
{
	char		*path;
	char		**path_array;

	if (!(path = get_env(sh, "PATH")))
		return (arg);
	path_array = ft_split(path, ':');
	free(path);
	if (!path_array)
	{
		put_error(strerror(errno));
		return (arg);
	}
	return (find_executable(arg, path_array));
}