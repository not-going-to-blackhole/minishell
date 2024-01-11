/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:55:31 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/11 14:34:15 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <termios.h>

# define SUCCESS 0
# define FAIL 1

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}					t_envlst;

typedef struct s_info
{
	int				stdin;
	int				stdout;
	int				syntax_error;
	struct termios	ms_termios;
	t_envlst		*env_list;
	char			**path_list;
}	t_info;


// reading
char		*read_input(void);

// token_utils
t_token		*new_token(char *str, int type);
int			add_token(t_token **token, char *str, int type);
int			split_tokens(t_token **tokens, char *line);

// env_utils
t_envlst	*new_envlst(char *key, char *value);
void		add_envlst(t_envlst **head, t_envlst *new);
void		init_envlst(t_envlst **head, char *envp[]);
void		get_path_list(t_info **info);
char		*get_env_value(t_envlst *head, char *key);

// builtin_pwd.c
int			dir_pwd(void);

// builtin_echo.c
int			mini_echo(char **av);

// builtin_cd.c
int			mini_cd(t_info *info, char **av);

// builtin_export.c
int			mini_export(t_info *info, char **av);

// utils.c
void		printf_error(char *str1, char *str2);
void		free_all(char **arr);


// // parsing test
// void	print_tokens(t_token *tokens);
// void	print_envplst(t_envlst *head);
// void	print_path_list(char **list);

#endif