#include "../includes/minishell.h"

static int is_valid_pipe(t_token *tokens)
{
    t_token *prev;
    t_token *cur;

    prev = NULL;
    cur = tokens;
    while (cur)
    {
        if (cur->type == PIPE)
        
        prev = cur;
        cur = cur->next;
    }
    return (1);
}

int do_syntax(t_token *tokens)
{
    if 
}