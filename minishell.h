/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:55:31 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/07 19:56:37 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

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
	char		    *key;
	char		    *value;
	struct s_envlst	*next;
}					t_envlst;

// reading
char	*read_input(void);

// token_utils
t_token	*new_token(char *str, int type);
int		add_token(t_token **token, char *str, int type);
int		split_tokens(t_token **tokens, char *line);

// env_utils
char	*strdup_from_to(char *str, int start, int end);
int		get_key_value(char **key, char **value, char *env);
t_envlst	*init_envlst(char **envp);

#endif