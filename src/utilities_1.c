/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 15:26:26 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/18 21:46:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char	***allocate_array(int line_count, int *arg_count)
{
	char	***array;
	int		i;

	i = 0;
	array = (char***)malloc(sizeof(char**) * line_count + 1);
	if (!array)
	{
		free_array(array, line_count, arg_count);
		put_error(strerror(errno));
		return (0);
	}
	array[line_count] = 0;
	while (i < line_count)
	{
		array[i] = (char**)malloc(sizeof(char*) * arg_count[i] + 1);
		if (!array[i])
		{
			free_array(array, line_count, arg_count);
			put_error(strerror(errno));
			return (0);
		}
		array[i][arg_count[i]] = 0;
		i++;
	}
	return (array);		
}

int		*allocate_counter(int line_count)
{
	int		*counter;

	counter = (int*)malloc(sizeof(int) * line_count);
	if (!counter)
	{
		put_error(strerror(errno));
		return (0);
	}
	return (counter);
}

int		**allocate_data(int line_count, int *arg_count)
{
	int		**data;
	int		i;

	i = 0;
	data = (int**)malloc(sizeof(int*) * line_count);
	if (!data)
	{
		free_data(data, line_count);
		put_error(strerror(errno));
		return (0);
	}
	while (i < line_count)
	{
		data[i] = (int*)malloc(sizeof(int) * arg_count[i]);
		if (!data[i])
		{
			free_data(data, line_count);
			put_error(strerror(errno));
			return (0);
		}
		i++;
	}
	return (data);
}

void    free_array(char ***array, int line_count, int *arg_count)
{
	int     x;
	int		y;

	x = 0;
	if (array)
	{
		while (x < line_count)
		{
			y = 0;
			if (array[x])
			{
				while (y < arg_count[x])
				{
					if (array[x][y])
						free(array[x][y]);
					y++;
				}
				free(array[x]);
			}
			x++;
		}
		free(array);
	}
}

void    free_data(int **data, int line_count)
{
	int     x;

	x = 0;
	if (data)
	{
		while (x < line_count)
		{
			if (data[x])
				free(data[x]);
			x++;
		}
		free(data);
	}
}
