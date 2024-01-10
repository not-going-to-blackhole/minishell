/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeun <yeeun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:55:31 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/10 13:35:38 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
// # include <readline/readline.h>
// # include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

#define SUCCESS     0
#define FAIL        1

typedef struct s_token
{
    char			*str;
    int				type;
    struct s_token	*next;
}					t_token;

typedef struct s_env_node
{
	char				*key;
	char				*val;
	struct s_env_node	*next;
}	t_env_node;
typedef struct s_info
{
	int				stdin;
	int				stdout;
	int				syntax_error;
	// struct termios	ms_termios;
	t_env_node		*env_list;
	char			**path_list;
}	t_info;

typedef struct s_info
{
	int				stdin;
	int				stdout;
	int				syntax_error;
	// struct termios	ms_termios;
	t_env_node		*env_list;
	char			**path_list;
}	t_info;

// reading
char *read_input(void);

// token_utils
t_token	*new_token(char *str, int type);
int	add_token(t_token **token, char *str, int type);
int split_tokens(t_token **tokens, char *line);

// builtin_pwd.c
int	dir_pwd(void);

// builtin_echo.c
int	mini_echo(char **av);

// builtin_cd.c
int	mini_cd(t_info *info, char **av);

// builtin_export.c
int	mini_export(t_info *info, char **av);

#endif