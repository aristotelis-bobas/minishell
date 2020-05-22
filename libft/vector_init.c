/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 23:48:42 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:37:22 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int		vector_init(t_vector *v)
{
	v->capacity = 128;
	v->total = 0;
	v->data = (char**)malloc(sizeof(char*) * v->capacity + 1);
	if (!v->data)
		return (0);
	return (1);
}
