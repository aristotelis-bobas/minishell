/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 18:53:36 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 19:03:09 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		count_digits(int n)
{
	int	count;

	count = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count++;
	}
	count++;
	if (n < 0)
		count++;
	return (count);
}

static char		*make_string(char *dst, int n, int i)
{
	int		b;

	if (n < 0)
	{
		dst[0] = '-';
		n = n * -1;
	}
	dst[i] = '\0';
	i--;
	while (n >= 10)
	{
		b = n % 10;
		n = n / 10;
		dst[i] = b + '0';
		i--;
	}
	dst[i] = (n % 10 + '0');
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*dst;

	dst = (char*)malloc(sizeof(char) * (count_digits(n) + 1));
	if (!dst)
		return (0);
	dst = make_string(dst, n, count_digits(n));
	return (dst);
}
