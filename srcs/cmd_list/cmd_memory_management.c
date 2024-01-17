/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_memory_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:31 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/01/17 11:00:49 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_redirection_memory(t_redirection *redirection_list)
{
	t_redirection	*tmp;

	while (redirection_list)
	{
		if (redirection_list->type)
			free(redirection_list->type);
		if (redirection_list->file)
			free(redirection_list->file);
		tmp = redirection_list;
		redirection_list = redirection_list->next;
		free(tmp);
	}
}

void	free_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*tmp;

	while (*cmd_list)
	{
		tmp = (*cmd_list)->next;
		free_all((*cmd_list)->argv);
		free_redirection_list((*cmd_list)->redirection);
		free(*cmd_list);
		*cmd_list = tmp;
	}
}
