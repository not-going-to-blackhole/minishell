/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:14:41 by yeeun             #+#    #+#             */
/*   Updated: 2024/01/10 15:56:31 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	dir_pwd(void)
{
	char	current_working_dir[1024];

	if (getcwd(current_working_dir, 1024) == NULL)
	{
		printf_error("pwd", 0);
		return (1);
	}
	ft_putendl_fd(current_working_dir, STDOUT_FILENO);
	return (0);
}