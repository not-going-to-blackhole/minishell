#include "../includes/minishell.h"


// void	print_tokens(t_token *tokens)
// {
// 	t_token	*tmp;
// 	char *type;

// 	tmp = tokens;
// 	while (tmp)
// 	{
// 		if (tmp->type == WORD)
// 			type = "WORD";
// 		else if (tmp->type == ARGV)
// 			type = "ARGV";
// 		else if (tmp->type == REDIR)
// 			type = "REDIRECT";
// 		else if (tmp->type == PIPE)
// 			type = "PIPE";
// 		else if (tmp->type == SPACING)
// 			type = "SEMICOLON";
// 		else
// 			type = "UNKNOWN";
// 		printf("str: %s\ntype: %s\n-------------\n", tmp->str, type);
// 		tmp = tmp->next;
// 	}
// }

t_token	*do_lexical(t_info *info, char *line)
{
	t_token	*tokens;

	tokens = new_token(line, WORD);
    check_heredoc(info, tokens);
	// print_tokens(tokens);
	return (tokens);
}