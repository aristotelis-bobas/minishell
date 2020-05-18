/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_populate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 01:04:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 02:17:27 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	vector_populate(t_vector *v, char **source)
{
	int		i;

	i = 0;
	while (source[i] != 0)
	{
		vector_add(v, ft_strdup(source[i]));
		i++;
	}
}
