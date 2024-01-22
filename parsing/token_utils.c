/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:48:07 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/22 12:17:53 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*new_token(char *str, int type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = ft_strdup(str);
	token->type = type;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **token, char *str, int type)
{
	t_token	*new;
	t_token	*tmp;

	new = new_token(str, type);
	if (!new)
		return ;
	if (!*token)
		*token = new;
	else
	{
		tmp = *token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	delete_token(t_token **head, t_token *target)
{
	t_token	*tmp;

	if (!*head || !target)
		return ;
	if (*head == target)
	{
		*head = (*head)->next;
		if (target->str)
			free(target->str);
		free(target);
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		if (tmp->next == target)
		{
			tmp->next = tmp->next->next;
			if (target->str)
				free(target->str);
			free(target);
			return ;
		}
		tmp = tmp->next;
	}
}

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
}
