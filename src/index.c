
#include "../include/minishell.h"

int  index_envvar(char *cmd, int i)
{
    while(cmd[i] && !find_space(cmd[i]))
        i++;
    return (i);
}

int index_single(char *cmd, int i)
{
    i++;
    while(cmd[i] && cmd[i++] != '\'');
    return (i);
}

int index_double(char *cmd, int i)
{
    i++;
    while(cmd[i] && cmd[i++] != '\"');
    return (i);
}

int index_cmd(char *cmd, int i)
{
    while (cmd[i] && !find_space(cmd[i]) && 
            cmd[i] != '<' && cmd [i] != '>' && cmd[i] != '|')
        i++;
    return (i);
}