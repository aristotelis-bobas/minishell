/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 00:53:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 19:37:11 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char        *get_env(t_minishell *sh, char *env)
{
	char	*tmp;
	
	if (!(tmp = vector_return(sh->env, env)))
		return (0);
	return (ft_substr(tmp, ft_strlen(env) + 1, ft_strlen(tmp)));
}