/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:44:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 15:52:30 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	vector_print(t_vector *v)
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		ft_printf("%s\n", v->data[i]);
		i++;
	}
}
