#include "../includes/minishell.h"

// void	print_tokens(t_token *tokens)
// {
// 	t_token	*tmp;

// 	tmp = tokens;
// 	while (tmp)
// 	{
// 		printf("str: %s, type: %d\n", tmp->str, tmp->type);
// 		tmp = tmp->next;
// 	}
// }

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

void	print_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmds;
	while (tmp)
	{
		i = 0;
		printf("cmds----------------\n");
		while (tmp->argv[i])
		{
			printf("argv[%d]: %s\n", i, tmp->argv[i]);
			i++;
		}
		if (tmp->redir)
		{
			printf("redir: %s\n", tmp->redir->type);
			printf("file: %s\n", tmp->redir->file);
		}
		tmp = tmp->next;
	}
}
