
#include "../include/minishell.h"

int  index_envvar(char *cmd, int i)
{
    if (cmd[i++] == '{')
        while (cmd[i] && cmd[i++] != '}');
    else if (cmd[i++] == '(')
        while (cmd[i] && cmd[i++] != ')');
    else
        while(cmd[i] && !find_space(cmd[i++]));
    return (i);
}

int index_cmd(char *cmd, int i)
{
    while (cmd[i] && !find_space(cmd[i]) && 
            cmd[i] != '<' && cmd [i] != '>' && cmd[i] != '|' && cmd[i] != '$')
        i++;
    return (i);
}