/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 01:45:37 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 13:51:35 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_readline(int fd, int buf_size)
{
	char	*dst;
	char	byte;
	int		i;

	dst = (char*)malloc(sizeof(char) * buf_size);
	if (!dst)
		return (0);
	i = 0;
	while (1)
	{
		if (read(fd, &byte, 1) <= 0)
			return (0);
		dst[i] = (byte == '\n' || byte == '\0') ? '\0' : byte;
		if (byte == '\n' || byte == '\0')
			return (dst);
		i++;
		if (i == buf_size)
		{
			buf_size += 64;
			dst = ft_realloc(dst, buf_size - 64, buf_size);
			if (!dst)
				return (0);
		}
	}
}
