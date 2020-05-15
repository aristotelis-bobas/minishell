/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:49:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 17:46:00 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_host(int fd, char *host)
{
	int		bufsize;
	int		i;
	char	ch;

	bufsize = 128;
	i = 0;
	while (1)
	{
		if (read(fd, &ch, 1) < 0)
			exit(EXIT_FAILURE);
		if (ch == '\n')
		{
			host[i] = '\0';
			return (host);
		}
		else
			host[i] = ch;
		i++;
		if (i == bufsize)
		{
			bufsize += 128;
			host = ft_reallocate(host, bufsize - 128, bufsize);
		}
	}
}

char	*get_host(void)
{
	int		fd;
	char	*host;

	fd = open("/proc/sys/kernel/hostname", O_RDONLY);
	host = (char*)malloc(sizeof(char) * 128);
	if (!host)
		exit(EXIT_FAILURE);
	host = read_host(fd, host);
	close(fd);
	return (host);
}

char	*get_workdir(t_minishell *sh)
{
	char	path[1024];
	char	*home;
	char	*work_dir;
	char	*temp;

	getcwd(path, 1024);
	home = get_env(sh, "HOME");
	if (!ft_envcmp(home, path))
	{
		temp = ft_substr(path, ft_strlen(home), ft_strlen(path) - ft_strlen(home));
		work_dir = ft_strjoin("~", temp);
		free(temp);
		return (work_dir);
	}
	work_dir = ft_strdup(path);
	return (work_dir);
}

void	print_prompt(t_minishell *sh)
{
	char	*host;
	char	*work_dir;
	char	*user;

	host = get_host();
	work_dir = get_workdir(sh);
	user = get_env(sh, "USER");
	ft_putstr(user);
	ft_putstr("@");
	ft_putstr(host);
	ft_putstr(":");
	ft_putstr(work_dir);
	ft_putstr("$ ");
	free(host);
	free(work_dir);
	free(user);
}
