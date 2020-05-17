/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:46:12 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/17 23:37:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/includes/libft.h"

typedef	struct		s_minishell
{
	t_vector		*env;
	char			*line;
	char			***args;
	int				**data;
	int				line_count;
	int				*arg_count;
}					t_minishell;

t_minishell		init_minishell(void);
t_vector		init_env(char **env);

void			reset(t_minishell *sh);
int				prompt(t_minishell *sh);
int				parse(t_minishell *sh);
int				parse_read(t_minishell *sh);
int				parse_split(t_minishell *sh);
int				parse_sanitize(t_minishell *sh);
int				parse_validate(t_minishell *sh);
int				parse_quotes(t_minishell *sh);

char			*get_env(t_minishell *sh, char *env);

char			***allocate_array(int line_count, int *arg_count);
int				**allocate_data(int line_count, int *arg_count);
int				*allocate_counter(int line_count);
void    		free_array(char ***array, int line_count, int *arg_count);
void			free_data(int **data, int line_count);

int				env_cmp(char *reference, char *data);
void			put_error(char *s);
int				is_space(char c);
int				is_semi(char *str);
int				is_literal(char *str);

void			debug_minishell(t_minishell *sh);

#endif
