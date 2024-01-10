/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:03 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/10 15:47:11 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

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

void	print_envplst(t_envlst *head)
{
	t_envlst	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("key: %s, value: %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_token		*tokens;
	t_envlst	*envlst;

	envlst = NULL;
	init_envlst(&envlst, envp);
	print_envplst(envlst);
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
