#include "../includes/minishell.h"




t_cmd	*new_cmd(void)
{
	t_cmd *cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redir = NULL;
	cmd->prev = NULL;
	cmd->next = NULL;
	return (cmd);
}

static int	argv_len(t_token *tokens)
{
	int len;

	len = 0;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == ARGV)
			len++;
		else if (tokens->type == REDIR)
			len--;
		tokens = tokens->next;
	}
	return (len);
}

static char	**argv_list(t_token *tokens)
{
	char	**argv;
	int		index;

	argv = (char **)malloc(sizeof(char *) * (argv_len(tokens) + 1));
	if (!argv)
		return (NULL);
	index = 0;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == ARGV)
			argv[index++] = ft_strdup(tokens->str);
		else if (tokens->type == REDIR)
			tokens = tokens->next;
		tokens = tokens->next;
	}
	argv[index] = NULL;
	return (argv);
}

t_redir	*new_redir(t_token *tokens)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = ft_strdup(tokens->str);
	redir->file = ft_strdup(tokens->next->str);
	redir->next = NULL;
	return (redir);
}

static	void	redir_list(t_cmd **cmds, t_token *tokens)
{
	t_redir	*redir;

	if ((*cmds)->redir == NULL)
	{
		(*cmds)->redir = new_redir(tokens);
	}
	else
	{
		redir = (*cmds)->redir;
		while (redir->next)
			redir = redir->next;
		redir->next = new_redir(tokens);
	}
}

t_cmd	*parse_cmds(t_token *tokens)
{
	t_cmd   *cmds;
	t_cmd   *head;

	cmds = new_cmd();
	head = cmds;
	while(tokens)
	{
		if (cmds->argv == NULL && tokens->type == ARGV)
            cmds->argv = argv_list(tokens);
		else if (tokens->type == REDIR)
		{
			redir_list(&cmds, tokens);
			tokens = tokens->next;
		}
		else if (tokens->type == PIPE)
		{
			cmds->next = new_cmd();
			cmds->next->prev = cmds;
			cmds = cmds->next;
		}
		tokens = tokens->next;
	}
	print_cmds(head);
	return (head);
}
