/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:03 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/07 16:44:18 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		printf("str: %s, type: %d\n", tmp->str, tmp->type);
		tmp = tmp->next;
	}
}

void	print_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("envp %d: %s\n", i, envp[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	*tokens;

	//print_envp(envp);
	(void)envp;
	(void)argc;
	(void)argv;
	tokens = NULL;
	while (42)
	{
		line = read_input();
		split_tokens(&tokens, line);
		free(line);
		print_tokens(tokens);
	}
	return (0);
}
