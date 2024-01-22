/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:10:16 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/22 12:11:52 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"  

void	sighandler_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		ft_putendl_fd("", STDOUT_FILENO);
		exit(1);
	}
}

void	sighandler_quit(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
	}
	exit(1);
}

void	sighandler_default(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd("minishell$", STDERR_FILENO);
		g_termination_status = 1;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	setting_signal(void)
{
	signal(SIGINT, sighandler_default);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
