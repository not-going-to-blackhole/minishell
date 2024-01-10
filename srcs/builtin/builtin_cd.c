/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:52:57 by yeeun             #+#    #+#             */
/*   Updated: 2024/01/10 15:58:44 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	setting_pwd(t_info *info, char *key)
{
	char	**av;
	char	current_working_dir[1024];

	av = malloc(sizeof(char *) * 3);
	if (!av)
		return ;
	getcwd(current_working_dir, 1024);
	av[0] = ft_strdup("export");
	av[1] = ft_strjoin(key, current_working_dir);
	av[2] = 0;
	mini_export(info, av);
	free_all(av);
}

int	mini_cd(t_info *info, char **av)
{
    char	*path;

	setting_pwd(info, "OLDPWD=");
	if (av[1] && (access(av[1], F_OK) || chdir(av[1])))
	{
		printf_error("cd", av[1]);
		return (1);
	}
	if (av[1] == NULL)
	{
		path = get_env_value_and_free_env_key(info->env_list,
				ft_strdup("HOME"));
		if (path[0] == '\0')
		{
			free(path);
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
			return (1);
		}
		chdir(path);
		free(path);
	}
	setting_pwd(info, "PWD=");
	return (0);
}