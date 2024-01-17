#include "../includes/minishell.h"

static void	get_exit_no(char **res)
{
	res[1] = ft_itoa(g_exit_no);
	res[2] = ft_strdup(" ");
	res[3] = ft_strdup("");
	res[4] = NULL;
}

static void	get_env_value(t_info *info, char **res, char *env)
{
	char	*env_val;

    // env도 잘라야 할 수 있나..
	env_val = get_envval(info->env_list, env);
	res[1] = ft_strdup(env_val);
	res[2] = ft_strdup(" ");
	res[3] = ft_strdup("");
	free(env_val);
}


char	**split_env(t_info *info, char *str)
{
	char	**res;
	int		start;
	int		end;

	if (!find_env_idx(str, &start, &end))
		return (NULL);
	res = malloc(sizeof(char *) * 6);
	if (!res)
		return (NULL);
	res[0] = ft_substr(str, 0, start);
	// (1)env_val + (2)" " + (3)""
	if (str[start + 1] == '?')
		get_exit_no(res);
	else
		get_env_value(info, res, ft_substr(str, start + 1, end - start - 1));
	res[4] = ft_substr(str, end, ft_strlen(str) - end);
	res[5] = NULL;
	return (res);
}