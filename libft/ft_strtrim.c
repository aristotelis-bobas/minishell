/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 14:51:19 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/17 14:55:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char *src, int n)
{
	char	*dst;
	int		i;
	int		y;
	int		length;

	length = ft_strlen(src) - (2 * n) + 1;
	if (length < 1)
		return (0);
	i = 0;
	y = n;
	dst = (char*)malloc(sizeof(char) * length);
	if (!dst)
		return (0);
	while (y < length)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (dst);
}
