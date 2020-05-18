/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 20:38:59 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 02:26:08 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (!str)
		return (0);
	dst = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		return (0);
	while (str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
