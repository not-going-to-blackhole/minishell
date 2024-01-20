/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:46:32 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/20 19:20:19 by woorikim         ###   ########.fr       */
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


t_envlst	*create_env_node(char *envp)
{
	int		loc;
	char	*key;
	char	*value;

	loc = 0;
	while (envp[loc] && envp[loc] != '=')
		loc++;
	key = ft_substr(envp, 0, loc);
	if (envp[loc] != '\0')
		value = ft_substr(envp, loc + 1, ft_strlen(envp) - loc - 1);
	else
		value = NULL;
	return (new_envlst(key, value));
}

void	init_envlst(t_envlst **head, char *envp[])
{
	*head = NULL;
	while (*envp != NULL && **envp != '\0')
	{
		add_envlst(head, create_env_node(*envp));
		envp++;
	}
	return ;
}

void	get_path_list(t_info **info)
{
	t_envlst	*tmp;

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
	char		*value;
	t_envlst	*tmp;

	tmp = head;
	while (tmp && (ft_strlen(key) != ft_strlen(tmp->key)
			|| ft_strncmp(key, tmp->key, ft_strlen(key))))
		tmp = tmp->next;
	if (tmp)
		value = ft_strdup(tmp->value);
	else
		value = ft_strdup("");
	free(key);
	return (value);
}

void	free_envlst(t_envlst *head)
{
	t_envlst	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}
char	**env_list_to_envp(t_envlst *env_list)
{
	char		**envp;
	int			cnt;
	t_envlst	*tmp;

	cnt = 0;
	tmp = env_list;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	envp = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!envp)
		return (NULL);
	cnt = 0;
	while (env_list)
	{
		envp[cnt] = ft_strjoin(env_list->key, "=");
		if (env_list->value)
			envp[cnt] = ft_strjoin(envp[cnt], env_list->value);
		env_list = env_list->next;
		cnt++;
	}
	envp[cnt] = NULL;
	return (envp);
}
