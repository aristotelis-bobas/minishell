/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_5.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 20:12:43 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/24 02:17:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a');
}

int		is_redirect(char c)
{
	return (c == '>' || c == '<');
}

void	put_error(char *s)
{
	write(2, "Minishell: ", 11);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}

