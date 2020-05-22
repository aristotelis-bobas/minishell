/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_set.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:39:28 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:39:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	vector_set(t_vector *v, int index, char *data)
{
	if (index >= 0 && index < v->total)
	{
		if (v->data[index])
			free(v->data[index]);
		v->data[index] = data;
	}
}
