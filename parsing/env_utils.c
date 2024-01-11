/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:46:32 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/11 14:26:25 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

	*head = NULL;
	while (*envp != NULL && **envp != '\0')
	{
		loc = 0;
		while ((*envp)[loc] && (*envp)[loc] != '=')
			loc++;
		key = ft_substr(*envp, 0, loc);
		value = ft_substr(*envp, loc + 1, ft_strlen(*envp) - loc - 1);
		add_envlst(head, new_envlst(key, value));
		envp++;
	}
	return ;
}

void	get_path_list(t_info **info)
{
	t_envlst *tmp;

	(*info)->path_list = NULL;
	tmp = (*info)->env_list;
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->key, "PATH", 5))
			break ;
		tmp = tmp->next;
	}
	if (!((*info)->env_list))
		return ;
	(*info)->path_list = ft_split(tmp->value, ':');
}

char	*get_envval(t_envlst *head, char *key)
{
	char	*value;
	t_envlst	*tmp;
	
	tmp = head;
	while (tmp && (ft_strlen(key) != ft_strlen(tmp->key) ||
			ft_strncmp(key, tmp->key, ft_strlen(key))))
		tmp = tmp->next;
	if (tmp)
		value = ft_strdup(tmp->value);
	else
		value = ft_strdup("");
	free(key);
	return (value);
}
