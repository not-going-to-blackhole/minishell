#include "../includes/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		printf("str: %s, type: %d\n", tmp->str, tmp->type);
		tmp = tmp->next;
	}
}

void	print_envplst(t_envlst *head)
{
	t_envlst	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("key: %s, value: %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	print_path_list(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		printf("path: %s\n", list[i]);
		i++;
	}
}