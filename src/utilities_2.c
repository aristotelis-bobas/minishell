/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 02:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 15:31:01 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <unistd.h>

void	put_error(char *s)
{
	write(2, "Minishell: ", 11);
	write(2, s, ft_strlen(s));
	write(2 , "\n", 1);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a');
}

int		is_literal(char *str)
{
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
}

int		is_semi(char *str)
{
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}
