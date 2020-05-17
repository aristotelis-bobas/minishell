/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 02:42:30 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 02:49:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_readfile(int fd, int buf_size)
{
	char	*buffer;
	char	*dst;
	char	*tmp;
	int		ret;

	ret = 1;
	dst = 0;
	while (ret > 0)
	{
		buffer = (char*)malloc(sizeof(char) * buf_size + 1);
		if (!buffer)
			return (0);
		ret = read(fd, buffer, buf_size);
		if (ret < 0)
			return (0);
		buffer[ret] = '\0';
		tmp = dst;
		dst = ft_strjoin(dst, buffer);
		if (!dst)
			return (0);
		free(buffer);
		if (tmp)
			free(tmp);
	}
	return (dst);
}
