/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:49:10 by yeeun             #+#    #+#             */
/*   Updated: 2024/01/11 11:08:21 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	if_key_exist_changing_val(t_info *info, char *key, char *val)
{
	t_env_node	*cur;

	cur = info->env_list;
	while (cur)
	{
		if (ft_strlen(cur->key) == ft_strlen(key) \
		&& ft_strncmp(cur->key, key, ft_strlen(key)) == 0)
		{
			if (ft_strncmp(key, "PATH", 4) == 0)
			{
				free_all(info->path_list);
				info->path_list = ft_split(val, ':');
			}
			if (val)
			{
				if (cur->val)
					free(cur->val);
				cur->val = ft_strdup(val);
			}
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

static void	print_env_list(t_env_node *env_list)
{
	while (env_list)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env_list->key, STDOUT_FILENO);
		if (env_list->val)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env_list->val, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		env_list = env_list->next;
	}
}

static int	is_key_vaild(char *key)
{
	int	idx;

    idx = 0;
	if (ft_isalpha(key[0]) == 0 && key[0] != '_')
		return (0);
	while (key[++idx])
		if (ft_isalnum(key[idx]) == 0 && key[idx] != '_')
			return (0);
	return (1);
}

static int	setting_error_flag(t_env_node *env_node, char *str, int *error_flag)
{
	char	*key;

	key = env_node->key;
	if (!is_key_vaild(key))
	{
		ft_putstr_fd("minishell: export: \'", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
		free_env_list(env_node);
		*error_flag = 1;
		return (1);
	}
	return (0);
}

int	mini_export(t_info *info, char **av)
{
	int			idx;
	int			flag_error;
    t_env_node	*new;

	idx = 0;
	flag_error = 0;
	while (av[++idx])
	{
		if (av[idx][0] == '\0')
			continue ;
		new = create_env_node(av[idx]);
		if (setting_error_flag(new, av[idx], &flag_error))
			continue ;
		else if (if_key_exist_changing_val(info, new->key, new->val))
			free_env_list(new);
		else
		{
			if (ft_strncmp(new->key, "PATH", 4) == 0)
				info->path_list = ft_split(new->val, ':');
			add_env_node(&info->env_list, new);
		}
	}
	if (idx == 1)
		print_env_list(info->env_list);
	return (flag_error);
}