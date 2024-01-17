#include "../includes/minishell.h"

static void    insert_tokens(t_token *tokens, char **str)
{
	t_token *tmp;
	t_token *tail;

	tail = tokens->next;
	tokens->next = NULL;
	free(tokens->str);
	tokens->str = ft_strdup(str[0]);
	if (str[1][0])
		add_token(&tokens, ft_strdup(str[1]), ARGV);
	if (str[3][0])
	{
		add_token(&tokens, ft_strdup(str[2]), SPACING);
		add_token(&tokens, ft_strdup(str[3]), ARGV);
	}
	tmp = tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tail;
	free_2dstr(str);
}

void    check_env(t_info *info, t_token *tokens)
{
    char    **str;

    while (tokens)
    {
        if (tokens->type == WORD)
        {
            str = split_env(info, tokens->str);
            if (str)
                insert_tokens(tokens, str);
        }
        tokens = tokens->next;
    }
}