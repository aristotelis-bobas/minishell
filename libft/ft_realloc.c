/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 02:04:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/28 19:24:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_realloc(char *src, int old_size, int new_size)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char*)malloc(sizeof(char) * new_size);
	if (!dst)
	{
		free(src);
		return (0);
	}
	while (i < old_size)
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	return (dst);
}
