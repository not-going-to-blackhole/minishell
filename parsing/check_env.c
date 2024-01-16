#include "minishell.h"

static char	**split_env(t_info *info, char *str)
{
	char	**res;
	char	*key;
	char	*value;
	int		loc;

	loc = 0;
	while (str[loc] && str[loc] != '=')
		loc++;
	key = ft_substr(str, 0, loc);
	if (str[loc] != '\0')
		value = ft_substr(str, loc + 1, ft_strlen(str) - loc - 1);
	else
		value = NULL;
	if (if_key_exist_changing_val(info, key, value))
	{
		free(key);
		free(value);
		return (NULL);
	}
	res = (char **)malloc(sizeof(char *) * 3);
	if (!res)
		return (NULL);
	res[0] = key;
	res[1] = value;
	res[2] = NULL;
	return (res);
}

// static  void    insert_tokens(t_token *tokens, char **str)
// {
// }

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