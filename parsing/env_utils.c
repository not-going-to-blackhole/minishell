/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:46:32 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/10 15:26:08 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envlst	*new_envlst(char *key, char *value)
{
	t_envlst	*new;

	new = (t_envlst *)malloc(sizeof(t_envlst));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_envlst(t_envlst **head, t_envlst *new)
{
	t_envlst	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	init_envlst(t_envlst **head, char *envp[])
{
	int		loc;
	char	*key;
	char	*value;

	while (*envp)
	{
		loc = 0;
		while ((*envp)[loc] != '=')
			loc++;
		key = ft_substr(*envp, 0, loc);
		value = ft_substr(*envp, loc + 1, ft_strlen(*envp) - loc - 1);
		add_envlst(head, new_envlst(key, value));
		envp++;
	}
	return ;
}
