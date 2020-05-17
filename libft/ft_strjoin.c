/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 22:03:44 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 02:24:48 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	copy(char *dst, char *src, int start)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[start] = src[i];
		start++;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	dst = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	if (s1)
	{
		copy(dst, s1, 0);
		i = ft_strlen(s1);
	}
	if (s2)
		copy(dst, s2, i);
	i += ft_strlen(s2);
	dst[i] = '\0';
	return (dst);
}
