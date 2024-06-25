#include "../include/minishell.h"

static t_type    else_type(char *cmd, int i)
{
    t_type type;

    if (cmd[i] == '|')
        type = PIPE;
    else if (cmd[i] == '-' && ft_isalpha(cmd[i + 1]))
        type = FLAG;
    else if (cmd[i] == '$' && (ft_isalpha(cmd[i + 1]) || 
                ft_isdigit(cmd[i + 1]) || cmd[i + 1] == '_'))
        type = ENV_VAR;
    else if (cmd[i] == '\'')
        type = SINGLE_QUOTE;
    else if (cmd[i] == '\"')
        type = DOUBLE_QUOTE;
    else
        type = CMD;
    return (type);
}

t_type  token_type(char *cmd, int i)
{
    t_type  type;

    if (cmd[i] == '<' && cmd[i + 1] == '<')
        type = HEREDOC;
    else if (cmd[i] == '>' && cmd[i + 1] == '>')
        type = APPEND;
    else if (cmd[i] == '<')
        type = REDIRECT_IN;
    else if (cmd[i] == '>')
        type = REDIRECT_OUT;
    else
        type = else_type(cmd, i);
    return (type);
}