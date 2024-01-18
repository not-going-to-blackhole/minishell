#include "../includes/minishell.h"  

void	term_print_off(t_info *info)
{
	// 터미널 속성 가져오기
	tcgetattr(STDIN_FILENO, &info->ms_termios);
	// 제어문자 표시 끄기
	(&info->ms_termios)->c_lflag &= ~(ECHOCTL);
	// 옵션 즉시 적용
	tcsetattr(STDIN_FILENO, TCSANOW, &info->ms_termios);
}

void	term_print_on(t_info *info)
{
	tcgetattr(STDIN_FILENO, &info->ms_termios); // 터미널 속성 가져오기
	(&info->ms_termios)->c_lflag |= ECHOCTL; // 제어문자 표시 켜기
	tcsetattr(STDIN_FILENO, TCSANOW, &info->ms_termios); // 옵션 즉시 적용
}

void	sighandler_heredoc(int signum)
{
	// ctrl + c : 줄바꿈 출력, 종료
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
	// ctrl + c 줄바꿈 출력
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
	signal(SIGTSTP, SIG_IGN); // ctrl + z
}
