/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_debug.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 01:09:09 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 15:44:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	vector_debug(t_vector *v)
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		ft_printf("data[%d] = \"%s\"\n", i, v->data[i]);
		i++;
	}
	ft_printf("data[%d] = \"%s\"\n", i, v->data[i]);
}
