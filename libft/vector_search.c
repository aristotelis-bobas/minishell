/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_search.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:49:41 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 14:57:04 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		vector_search(t_vector *v, char *reference)
{
	int		index;

	index = 0;
	while (index < v->total)
	{
		if (!ft_strcmp(v->data[index], reference))
			return (index);
		index++;
	}
	return (0);
}
