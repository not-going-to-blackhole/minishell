/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:46:32 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/07 20:06:53 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strdup_from_to(char *str, int start, int end)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	if (ft_strlcpy(res, str + start, end - start + 1) == 0)
		return (NULL);
	return (res);
}

int	get_key_value(char **key, char **value, char *env)
{
	int	i;

	i = 0;
	printf("env : %s\n", env);
	while (env[i] != '=')
		i++;
	if (i == 0)
		return (FAIL);
	*key = strdup_from_to(env, 0, i);
	if (!(*key))
		return (FAIL);
	i++;
	*value = strdup_from_to(env, i, ft_strlen(env));
	if (!(*value))
		return (FAIL);
	return (SUCCESS);
}

void	add_envlst(t_envlst *head, t_envlst *new)
{
	t_envlst	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_envlst	*init_envlst(char **envp)
{
	t_envlst	*head;
	t_envlst	*tmp;
	
	head = NULL;
	tmp = head;
	while (*envp)
	{
		tmp = (t_envlst *)malloc(sizeof(t_envlst));
		if (!tmp)
			return (NULL);
		tmp->key = NULL;
		tmp->value = NULL;
		tmp->next = NULL;
		if (get_key_value(&(tmp->key), &(tmp->value), *envp) == FAIL)
			return (NULL);
		if (!head)
			head = tmp;
		else
			add_envlst(head, tmp);
		envp++;
	}
	return (head);
}
