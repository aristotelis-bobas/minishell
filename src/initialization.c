/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 03:49:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 15:20:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>

t_vector	init_env(char **env)
{
	t_vector		v;

	vector_init(&v);
	vector_populate(&v, env);
	if (!v.data)
	{
		put_error("Retrieving environment variables has failed");
		exit(1);
	}
	return (v);
}

t_minishell	init_minishell(void)
{
	t_minishell		sh;

	sh.env = 0;
	sh.line = 0;
	sh.args = 0;
	sh.data = 0;
	sh.line_count = 0;
	sh.arg_count = 0;
	return (sh);
}
