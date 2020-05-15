/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 17:35:54 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/15 17:35:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_array(t_minishell *sh)
{
	int		i;
	int		length;
	char	**new_array;
	
	i = 0;
	length = 0;
	while (i < sh->arg_count)
	{
		if (sh->args[i] != 0)
			length++;
		i++;
	}
	new_array = (char**)malloc(sizeof(char *) * length + 1);
	if (new_array == 0)
		exit(EXIT_FAILURE);
	return (new_array);
}

void	fill_array(t_minishell *sh, char **new_array)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < sh->arg_count)
	{
		if (sh->args[i] != 0)
		{
			new_array[y] = ft_strdup(sh->args[i]);
			y++;
		}
		i++;
	}
	new_array[y] = 0;
	free_args(sh);
	sh->arg_count = y;
	sh->args = new_array;	
}

void	prep_args(t_minishell *sh)
{
	char	**new_array;
	
	new_array = make_array(sh);
	fill_array(sh, new_array);
}