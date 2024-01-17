/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:52:57 by yeeun             #+#    #+#             */
/*   Updated: 2024/01/17 10:13:58 by yeeunpar         ###   ########.fr       */
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
	// chdir -> 현재 경로를 이동해주는 함수 (성공시 0, 실패시 -1 리턴)
	if (av[1] && (access(av[1], F_OK) || chdir(av[1])))
	{
		printf_error("cd", av[1]);
		return (1);
	}
	if (av[1] == NULL)
	{
		// get_env_value_and_free_env_key -> parsing 부분 함수인가?
		path = get_env_value_and_free_env_key(info->env_list,
				ft_strdup("HOME"));
		if (path[0] == '\0')
		{
			free(path);
			ft_putendl_fd("minishell: cd: HOME not setting", STDERR_FILENO);
			return (1);
		}
		chdir(path);
		free(path);
	}
	setting_pwd(info, "PWD=");
	return (0);
}