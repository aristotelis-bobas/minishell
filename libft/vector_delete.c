/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:45:23 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 01:02:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	vector_delete(t_vector *v, int index)
{
	if (index < 0 || index >= v->total)
		return ;
	v->data[index] = 0;
	while (index < v->total - 1)
	{
		v->data[index] = v->data[index + 1];
		v->data[index + 1] = 0;
		index++;
	}
	v->total--;
}
