/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:26:17 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:36:31 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	vector_free(t_vector *v)
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		if (v->data[i])
			free(v->data[i]);
		i++;
	}
	free(v->data);
}
