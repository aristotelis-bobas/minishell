/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:29:36 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:35:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		vector_add(t_vector *v, char *data)
{
	if (v->capacity == v->total)
	{
		if (!vector_resize(v, v->capacity * 2))
			return (0);
	}
	v->data[v->total] = data;
	v->data[v->total + 1] = 0;
	v->total++;
	return (1);
}
