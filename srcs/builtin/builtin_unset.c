#include "../../includes/minishell.h"

// 노드 삭제 함수
static t_envlst	*delete_env_list(t_envlst *env_list)
{
	t_envlst	*next;

	next = env_list->next;
	free(env_list->key);
	if (env_list->value)
		free(env_list->value);
	free(env_list);
	return (next);
}

// str이 숫자로 시작하면 유효하지 않다는 에러 문구 출력 -> error_flag : 1
static void	set_error_flag(char *str, int *error_flag)
{
	if (ft_isdigit(str[0]))
	{
		ft_putstr_fd("minishell: unset: \'", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
		*error_flag = 1;
	}
}

// 실제로 환경 변수를 제거하는 함수
// 환경 변수가 "PATH"인 경우에는 info 구조에서 path_list를 해제
static int	operation_unset(t_info *info, t_envlst *cur, t_envlst *prev, char *str)
{
	if (ft_strlen(cur->key) == ft_strlen(str) \
	&& ft_strncmp(cur->key, str, ft_strlen(str)) == 0)
	{
		if (ft_strncmp(cur->key, "PATH", 4) == 0)
		{
			free_all(info->path_list);
			info->path_list = NULL;
		}
		if (prev == NULL)
			info->env_list = delete_env_list(cur);
		else
			prev->next = delete_env_list(cur);
		return (1);
	}
	return (0);
}

// av를 순회하면서 operation_unset을 호출해서 삭제 도전!
int	mini_unset(t_info *info, char **av)
{
	t_envlst	*cur;
	t_envlst	*prev;
	int			idx;
	int			error_flag;

	idx = 0;
	error_flag = 0;
	while (av[++idx])
	{
		set_error_flag(av[idx], &error_flag);
		cur = info->env_list;
		prev = NULL;
		while (cur)
		{
			if (operation_unset(info, cur, prev, av[idx]))
				break ;
			prev = cur;
			cur = cur->next;
		}
	}
	return (error_flag);
}