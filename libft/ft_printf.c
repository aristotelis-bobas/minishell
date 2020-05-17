/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 21:13:08 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/16 00:28:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdarg.h>

void	print_s(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr(s);
}

void	print_d(int n)
{
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	ft_putnbr_base(n, 10);
}

void	process(va_list ap, char *str, int i)
{
	if (str[i] == 's')
		print_s(va_arg(ap, char *));
	if (str[i] == 'd')
		print_d(va_arg(ap, int));
}

void	ft_printf(char *str, ...)
{
	va_list		ap;
	int			i;

	va_start(ap, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
		{
			i++;
			process(ap, str, i);
		}
		i++;
	}
	va_end(ap);
}
