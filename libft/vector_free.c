/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:26:17 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 00:59:55 by abobas        ########   odam.nl         */
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
		free(v->data[i]);
		i++;
	}
	free(v->data);
}
