#include "../includes/minishell.h"

static void	insert_tokens(t_token *tokens, char **res)
{
	t_token	*tmp;
	t_token	*tail;

	tail = tokens->next;
	tokens->next = NULL;
	free(tokens->str);
	tokens->str = ft_strdup(res[0]);
	add_token(&tokens, ft_strdup(res[1]), ARGV);
	add_token(&tokens, ft_strdup(res[2]), WORD);
	tmp = tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tail;
	free_2dstr(res);
}

void	check_quotation(t_info *info, t_token *tokens)
{
	char	**str;

	while (tokens)
	{
		if (tokens->type == WORD)
		{
			str = split_quotation(info, tokens->str);
			if (str)
				insert_tokens(tokens, str);
		}
		tokens = tokens->next;
	}
}
