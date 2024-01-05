/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:48:07 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/05 14:36:50 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *str, int type)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
	token->next = NULL;
	return (token);
}

int	add_token(t_token **token, char *str, int type)
{
	t_token *new;
	t_token *tmp;

	new = new_token(str, type);
	if (!new)
		return (FAIL);
	if (!*token)
		*token = new;
	else
	{
		tmp = *token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (SUCCESS);
}

int split_tokens(t_token **tokens, char *line) 
{
	char	**splited_str;
	int		i;
	
	*tokens = NULL;
	splited_str = ft_split(line, ';');
	if (!splited_str)
		return (FAIL);
	i = 0;
	while (splited_str[i])
	{
		if (add_token(tokens, splited_str[i], 0)  == FAIL)
			return (FAIL);
		i++;
	}
    return (SUCCESS);
}