#include "../../includes/minishell.h"

int	mini_env(t_envlst *envlst)
{
    // 환경 변수 리스트를 순회(envlst가 null이 아닌 동안) 하면서 각 환경 변수의 키와 값에 대한 정보 출력
    // key = 값 형태로 출력
	while (envlst)
	{
		if (envlst->val)
		{
			ft_putstr_fd(envlst->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(envlst->val, STDOUT_FILENO);
		}
		envlst = envlst->next;
	}
	return (0);
}
