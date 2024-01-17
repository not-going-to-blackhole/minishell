/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:03 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/17 14:16:04 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

static void	update_pwd(t_info *info)
{
	char	**pwd;
	int		i;

	pwd = (char **)malloc(sizeof(char *) * 3);
	if (!pwd)
		return ;
	pwd[0] = ft_strdup("");
	pwd[1] = ft_strdup("OLDPWD");
	pwd[2] = NULL;
	(void)info;
	//mini_unset(info, pwd);
	//mini_export(info, pwd);
	i = 0;
	while(pwd[i])
	{
		if (pwd[i])
			free(pwd[i]);
		i++;
	}
	free(pwd);
}

static void	info_init(t_info *info, char **envp)
{
	init_envlst(&info->env_list, envp);
	get_path_list(&info);
	info->stdin = dup(STDIN_FILENO);
	info->stdout = dup(STDOUT_FILENO);
	tcgetattr(STDIN_FILENO, &info->ms_termios); // 터미널 속성 가져오기
	(&info->ms_termios)->c_lflag &= ~(ECHOCTL); // 제어문자 표시 끄기
	tcsetattr(STDIN_FILENO, TCSANOW, &info->ms_termios); // 옵션 즉시 적용
	update_pwd(info);
}

static void	parse_line(t_info *info, char *line)
{
	t_token	*tokens;
	//t_cmd	*cmds;
	
	info->syntax_error = 0;
	tokens = do_lexical(info, line);
	if 
}


int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_info		info;
	info_init(&info, envp);
	
	(void)argc;
	(void)argv;
	while (42)
	{
		//setting signal
		line = read_input();
		if (!line)
		{
			//ms_exit(&info, NULL);
			break ;
		}
		else if (line[0] != '\0')
		{
			//printf("input %s \n", line);
			parse_line(&info, line);
		}
		free(line);	
	}
	return (0);
}
