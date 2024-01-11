#include "../includes/minishell.h"


int	get_insertion_loc(char *str)
{
	int	start;
	int	skip;

	start = 0;
	while (str[start] && ft_strncmp(&str[start], "<<", 2))
	{
		skip = 1;
		if (str[start] == '\'' || str[start] == '\"')
		{
			while (str[skip] && str[skip] != str[start])
				skip++;
			skip++;
		}
		start += skip;
	}
	return (start);
}

static void	parse_heredoc(t_info *info, t_token *token, char *str)
{
	int		loc;
	//char	*new;
	(void)info;
	(void)token;

	if (!str)
		return ;
	loc = get_insertion_loc(str);
}


static void	check_heredoc(t_info *info, t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == WORD)
			parse_heredoc(info, tmp, ft_strdup(tmp->str));
		tmp = tmp->next;
	}
}

t_token	*do_lexical(t_info *info, char *line)
{
	t_token	*tokens;

	tokens = new_token(line, WORD);
    check_heredoc(info, tokens);
	return (tokens);
}