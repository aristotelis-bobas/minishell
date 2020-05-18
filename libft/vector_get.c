/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 00:37:50 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 00:59:52 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
		return (v->data[index]);
	return (0);
}
