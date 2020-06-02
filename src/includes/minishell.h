/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:46:12 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/06/01 16:37:42 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/includes/libft.h"

typedef	struct	s_minishell
{
	t_vector	*env;
	char		*line;
	char		***args;
	int			**data;
	int			**file_descriptor;
	int			line_count;
	int			*arg_count;
	int			saved_stdout;
	int			saved_stdin;
}				t_minishell;

char			*g_prompt;

t_minishell		init_minishell(void);
t_vector		init_env(char **env);

void			reset(t_minishell *sh);
int				prompt(t_minishell *sh);
int				signal_handler_parent(void);
void			signal_handler_child(void);
int				parse(t_minishell *sh);
int				parse_read(t_minishell *sh);
int				parse_split(t_minishell *sh);
int				parse_sanitize(t_minishell *sh);
int				parse_validate(t_minishell *sh);
int				parse_quotes(t_minishell *sh);
int				parse_expand(t_minishell *sh);
int				expand_error(char *dst);
int				expand(int j, char *dst, char *env, t_minishell *sh);
int				expand_start_check(int start, char *src, int i);
int				parse_expand_home(t_minishell *sh);
int				parse_quote_count(char *s, int data);
char			*expand_arg(t_minishell *sh, char *dst, char *src, int i);
char			*expand_var(t_minishell *sh, char *src);
int				parse_pipe(t_minishell *sh);
int				parse_redirect(t_minishell *sh);

void			evaluate(t_minishell *sh);
void			pwd(t_minishell *sh);
void			echo(int ac, char **av, t_minishell *sh);
void			cd_1(int ac, char **av, t_minishell *sh);
void			quit(int ac, char **av);
void			ft_exit(int arg_count, char **args, t_minishell *sh);

void			env_add(char *reference, t_vector *v);
void			env_delete(char *reference, t_vector *v);
void			env_show(t_minishell *sh);
void			export_1(int ac, char **av, t_minishell *sh);
void			unset(int ac, char **av, t_minishell *sh);

void			execute(char **av, t_minishell *sh);
char			*get_executable(char *arg, t_minishell *sh);

char			***allocate_array(int line_count, int *arg_count);
int				**allocate_data(int line_count, int *arg_count);
int				**allocate_file_descriptor(int line_count);
int				*allocate_counter(int line_count);
void			free_file_descriptor(int **file_descriptor, int line_count);
void			free_array(char ***array, int line_count, int *arg_count);
void			free_data(int **data, int line_count);
int				env_cmp(char *reference, char *data);
int				vector_search_env(t_vector *v, char *reference);
char			*get_env(t_minishell *sh, char *env);
char			*get_identifier(char *reference);
int				traverse_word(t_minishell *sh, int i);
int				trav_word_util(t_minishell *sh, int i, int count, int start);
int				split_sub(t_minishell *sh, int i, int x, int y);
int				count_args_helper(t_minishell *sh, int i, int y);
int				array_helper(t_minishell *sh, char ***arr, int i, int x);
int				sanitize_data(t_minishell *sh, int lc, int *ac);
char			***fill_pipe_array(t_minishell *sh, char ***arr, int i);
int				**fill_data(int **data, t_minishell *sh);
int				**fill_pipe_data_1(int **data, t_minishell *sh, int a);
int				**fill_pipe_file_descriptor(int **file_descriptor, \
				t_minishell *sh, int i);
int				*count_pipe_args_1(t_minishell *sh, int *arg_count, int i);
int				expand_length(t_minishell *sh, char *src);
int				count_pipes(char **arg);
int				check_pipes(char **arg);
void			put_error(char *s);
int				is_space(char c);
int				is_double_quote(char *str);
int				is_single_quote(char *str);
int				is_var(char *str);
int				is_var_char(char c);
int				is_redirect(char c);
int				is_pipe(char c);
int				is_env(char *str);

void			debug(t_minishell *sh);

#endif
