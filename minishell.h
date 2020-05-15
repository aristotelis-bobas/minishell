/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:46:12 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/05/15 17:16:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct		s_env
{
	char			*data;
	struct s_env	*next;
}					t_env;

typedef	struct		s_minishell
{
	char			*line;
	char			**args;
	int				*bool;
	int				arg_count;
	int				arg_index;
	t_env			*first_element;
}					t_minishell;

void			print_prompt(t_minishell *sh);
void			read_input(t_minishell *sh);
void			split_input(t_minishell *sh);
int				input_check(t_minishell *sh);
void			parse_input(t_minishell *sh);
void			parse_env(t_minishell *sh);
void			prep_args(t_minishell *sh);
void			execute(t_minishell *sh);

//void			launch(t_minishell *sh);

void			setup_list(t_minishell *sh, char **env);
void			list_push_back(t_env **first_element, char *data);
void			list_remove_if(t_env **first_element, char *ref_data);
t_env			*create_element(char *data);

void			builtin_cd(t_minishell *sh);
void			builtin_exit(void);
void			builtin_pwd(void);
void			builtin_echo(t_minishell *sh);

char			*get_env(t_minishell *sh, char *env);
void			env_show(t_minishell *sh);
void			env_export(t_minishell *sh);
void			env_unset(t_minishell *sh);

void			clean(t_minishell *sh);
void			free_args(t_minishell *sh);

int				ft_isspace(char c);
int				ft_strlen(char *s);
void			ft_putstr(char *s);
void			ft_putendl(char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_substr(char *s, int start, int len);
char			*ft_strdup(char *str);
void			ft_error(char *s);
int				ft_envcmp(char *s1, char *s2);
char 			*ft_reallocate(char *line, int prev, int new);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_trim(char *src);


/// TROUBLESHOOTING FUNCTIONS //

void			show_args(t_minishell *sh);


#endif
