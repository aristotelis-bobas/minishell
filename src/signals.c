/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 15:37:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/01 16:38:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void	signal_catch_parent(int signal)
{
	if (signal == SIGINT)
		ft_printf("\n%s", g_prompt);
}

void	signal_catch_child(int signal)
{
	signal = signal;
}

int		signal_handler_parent(void)
{
	if (signal(SIGINT, signal_catch_parent) == SIG_ERR)
	{
		put_error(strerror(errno));
		return (0);
	}
	if (signal(SIGQUIT, signal_catch_parent) == SIG_ERR)
	{
		put_error(strerror(errno));
		return (0);
	}
	return (1);
}

void	signal_handler_child(void)
{
	if (signal(SIGINT, signal_catch_child) == SIG_ERR)
		put_error(strerror(errno));
	if (signal(SIGQUIT, signal_catch_child) == SIG_ERR)
		put_error(strerror(errno));
}
