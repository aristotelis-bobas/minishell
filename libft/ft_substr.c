/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 21:48:41 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 18:08:50 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char *str, int start, int length)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char*)malloc(sizeof(char) * (length + 1));
	if (!dst)
		return (0);
	while (i < length && str[start] != '\0')
	{
		dst[i] = str[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
