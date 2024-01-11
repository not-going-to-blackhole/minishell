/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:03 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/10 18:25:51 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

static void	info_init(t_info *info, char **envp)
{
	init_envlst(&info->env_list, envp);
	get_path_list(&info);
	
}

int	main(int argc, char **argv, char **envp)
{
	//char		*line;
	//t_token		*tokens;
	t_info		info;
	info_init(&info, envp);
	
	(void)argc;
	(void)argv;
	//tokens = NULL;
	// while (42)
	// {
	// 	line = read_input();
	// 	split_tokens(&tokens, line);
	// 	free(line);
	// 	print_tokens(tokens);
	// }
	return (0);
}
