/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 21:14:01 by abobas        #+#    #+#                 */
/*   Updated: 2020/05/22 19:02:13 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct		s_vector
{
	char	**data;
	int		capacity;
	int		total;
}					t_vector;

char				*vector_get(t_vector *v, int index);
int					vector_total(t_vector *v);
int					vector_search(t_vector *v, char *reference);
int					vector_init(t_vector *v);
int					vector_resize(t_vector *v, int capacity);
int					vector_populate(t_vector *v, char **source);
int					vector_add(t_vector *v, char *data);
void				vector_print(t_vector *v);
void				vector_debug(t_vector *v);
void				vector_free(t_vector *v);
void				vector_set(t_vector *v, int index, char *data);
void				vector_delete(t_vector *v, int index);

char				**ft_split(char *str, char c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *str, int start, int length);
char				*ft_strdup(char *str);
char				*ft_strtrim(char *src, int n);
char				*ft_realloc(char *src, int old_size, int new_size);
char				*ft_readline(int fd, int buf_size);
char				*ft_readfile(int fd, int buf_size);
char				*ft_itoa(int n);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int n);
int					ft_strlen(char *str);
void				ft_printf(char *str, ...);
void				ft_putstr(char *str);
void				ft_putnbr_base(int n, int base);
void				ft_putchar(char c);

#endif
