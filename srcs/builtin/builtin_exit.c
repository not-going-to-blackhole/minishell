#include "../../includes/minishell.h"

// 문자열을 long long 정수로 반환하는 함수
// str : 변환할 문자열, n : 변환된 값이 저장될 포인터
static int	mini_change_longlong(char *str, long long *n)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (sign == -1 && ft_strlen(str) == 19 \
	&& ft_strncmp(str, "9223372036854775808", 19) == 0)
	{
        // -992~~ 이게 설정될 경우에는 MIN 값으로 설정하고 1 반환
		*n = -9223372036854775807 - 1;
		return (1);
	}
	while (ft_isdigit(*str) && num * 10 + (*str - '0') >= num)
		num = num * 10 + (*str++ - '0');
    // 변환이 불가능할 경우에는 0 반환
	if (*str)
		return (0);
	*n = sign * num;
	return (1);
}

// exit 인자에 따라 termination_status(전역변수, 쉘이 종료될 때 사용되는 종료 상태를 냄) 설정
// 변환이 불가능한 경우 에러 메시지 출력후 termination_status 를 255로 설정
static void	set_exit_status(int arg_cnt, char *str)
{
	long long	exit_status;

	if (arg_cnt == 2)
	{
		if (mini_change_longlong(str, &exit_status))
			termination_status = (unsigned char)exit_status;
		else
		{
			ft_putstr_fd("minishell: exit: ", STDOUT_FILENO);
			ft_putstr_fd(str, STDOUT_FILENO);
			ft_putendl_fd(": numeric argument required", STDOUT_FILENO);
			termination_status = 255;
		}
	}
	else
		termination_status = 0;
}

// exit 명령어를 처리 후 쉘 종료
// 환경 변수와 경로 리스트를 해제하고 termination_status로 프로그램 종료
int	mini_exit(t_info *info, t_cmd *cmd_list)
{
	int	arg_cnt;

	dup2(info->stdout, STDOUT_FILENO);
	if (cmd_list)
	{
		arg_cnt = 0;
		while (cmd_list->argv[arg_cnt])
			arg_cnt++;
		if (cmd_list->prev == NULL && cmd_list->next == NULL)
			ft_putendl_fd("exit", STDOUT_FILENO);
		if (arg_cnt > 2)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STDOUT_FILENO);
			return (1);
		}
		set_exit_status(arg_cnt, cmd_list->argv[1]);
		unlink_heredoc_tmp(cmd_list);
		free_cmd_list(&cmd_list);
	}
	else
		ft_putendl_fd("exit", STDOUT_FILENO);
	// free_envlst(info->env_list);
	free_all(info->path_list);
	exit(termination_status);
	return (0);
}