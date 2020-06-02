/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 12:34:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/30 14:49:51 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi_i(const char *str, char *arg)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '+' && str[i + 1] != '-')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		arg[0] = 'f';
	return (i);
}

int		ft_atoi(const char *str, char *arg)
{
	int					factor;
	unsigned long long	result;
	unsigned long long	max;
	int					i;

	max = 9223372036854775807;
	result = 0;
	i = ft_atoi_i(str, arg);
	factor = (str[i] == '-') ? -1 : 1;
	arg[1] = (str[i] == '-') ? 'g' : arg[1];
	i = (str[i] == '-') ? i + 1 : i;
	if (!ft_isdigit(str[i]))
		arg[0] = 'f';
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if ((result > max && factor == 1) || (result > max + 1 && factor == -1))
			arg[0] = 'f';
		if ((result > max && factor == 1) || (result > max + 1 && factor == -1))
			return (0);
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		arg[0] = 'f';
	return (factor * (int)result);
}
