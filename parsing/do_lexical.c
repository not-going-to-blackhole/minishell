#include "../includes/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;
	char	*type;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == WORD)
			type = "WORD";
		else if (tmp->type == ARGV)
			type = "ARGV";
		else if (tmp->type == REDIR)
			type = "REDIRECT";
		else if (tmp->type == PIPE)
			type = "PIPE";
		else if (tmp->type == SPACING)
			type = "SPACING";
		else
			type = "UNKNOWN";
		printf("str: <%s>\ntype: %s\n-------------\n", tmp->str, type);
		tmp = tmp->next;
	}
}

static void	delete_useless(t_token *tokens)
{
	t_token *prev;
	t_token	*cur;
	
	cur = tokens;
	prev = cur;
	while (cur)
	{
		if (cur->type == WORD)
		{
			if (cur->str[0] != '\0')
				cur->type = ARGV;
			else
			{
				delete_token(&tokens, cur);
				cur = prev;
			}
		}
		prev = cur;
		cur = cur->next;
	}
}

t_token	*do_lexical(t_info *info, char *line)
{
	t_token	*tokens;

	tokens = new_token(line, WORD);
	check_heredoc(info, tokens);
	check_quotation(info, tokens);
	check_env(info, tokens);
	parse_by_delimiter(tokens);
	delete_useless(tokens);
	print_tokens(tokens);
	return (tokens);
}
