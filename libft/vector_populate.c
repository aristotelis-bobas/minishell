/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_populate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 01:04:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:42:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		vector_populate(t_vector *v, char **source)
{
	int		i;
	char	*tmp;

	i = 0;
	while (source[i] != 0)
	{
		tmp = ft_strdup(source[i]);
		if (!tmp)
			return (0);
		if (!vector_add(v, tmp))
			return (0);
		i++;
	}
	return (1);
}
