/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:15:14 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/01/17 11:15:16 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_env(t_envlst *envlst)
{
    // 환경 변수 리스트를 순회(envlst가 null이 아닌 동안) 하면서 각 환경 변수의 키와 값에 대한 정보 출력
    // key = 값 형태로 출력
	while (envlst)
	{
		if (envlst->value)
		{
			ft_putstr_fd(envlst->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(envlst->value, STDOUT_FILENO);
		}
		envlst = envlst->next;
	}
	return (0);
}
