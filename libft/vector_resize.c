/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_resize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 23:53:44 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:38:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int		vector_resize(t_vector *v, int capacity)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)malloc(sizeof(char*) * capacity + 1);
	if (!new)
		return (0);
	while (i < v->total)
	{
		new[i] = ft_strdup(v->data[i]);
		if (!new[i])
			return (0);
		i++;
	}
	new[i] = 0;
	vector_free(v);
	v->data = new;
	v->capacity = capacity;
	return (1);
}
