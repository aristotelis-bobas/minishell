/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:46:12 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/24 01:48:40 by abobas        ########   odam.nl         */
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
	int				**file_descriptors;
	int				line_count;
	int				*arg_count;
	int				saved_stdout;
	int				saved_stdin;
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
int				parse_expand(t_minishell *sh);
int				parse_redirect(t_minishell *sh);

void			evaluate(t_minishell *sh);
void			pwd(t_minishell *sh);
void			echo(int ac, char **av, t_minishell *sh);
void			cd(int ac, char **av, t_minishell *sh);

void			env_add(char *reference, t_vector *v);
void			env_delete(char *reference, t_vector *v);
void			env_show(t_minishell *sh);
void			export(int ac, char **av, t_minishell *sh);
void			unset(int ac, char **av, t_minishell *sh);

void			execute(char **av, t_minishell *sh, int i);
char			*get_executable(char *arg, t_minishell *sh);

char			***allocate_array(int line_count, int *arg_count);
int				**allocate_data(int line_count, int *arg_count);
int				*allocate_counter(int line_count);
int				allocate_file_descriptors(t_minishell *sh);
void			free_file_descriptors(t_minishell *sh, int line_count);
void    		free_array(char ***array, int line_count, int *arg_count);
void			free_data(int **data, int line_count);
int				env_cmp(char *reference, char *data);
int				vector_search_env(t_vector *v, char *reference);
char			*get_env(t_minishell *sh, char *env);
char			*get_identifier(char *reference);
int				expand_length(t_minishell *sh, char *src);
void			put_error(char *s);
int				is_space(char c);
int				is_double_quote(char *str);
int				is_single_quote(char *str);
int				is_var(char *str);
int				is_var_char(char c);
int				is_redirect(char c);
int				is_env(char *str);

void			debug(t_minishell *sh);

#endif
