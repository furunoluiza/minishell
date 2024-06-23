#include "../include/minishell.h"

static void	add_node(t_token **list, char *array, t_type type)
{
    t_token *node;
    t_token *current;

    current = *list;
	node = malloc(sizeof(t_token));
    if (!node)
    {
        return ;
    }
	node->data = array;
    node->type = type;
	node->next = NULL;
    if (*list == NULL)
        *list = node;
	else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = node;
    }
}

static char *data_array(char *cmd, int start, int end)
{
    int     i;
    char    *array;

    i = 0;
    array = malloc(sizeof(char) * ((end - start) + 1));
    while(start < end)
        array[i++] = cmd[start++];
    array[i] = '\0';
    return (array);
}

static t_type    token_type(char *cmd, int i)
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
    else if (cmd[i] == '|')
        type = PIPE;
    else
        type = CMD;
    return (type);
}

static int  type_index(t_type type, char *cmd, int i)
{
    if (type == HEREDOC || type == APPEND)
            i += 2;
    else if (type == CMD)
    {
        while (cmd[i] && !find_space(cmd[i]) && 
                cmd[i] != '<' && cmd [i] != '>' && cmd[i] != '|')
            i++;
    }
    else
        i++;
    return (i);
}

void    tokenizator(char *cmd)
{
    int     i;
    int     start;
    char    *array;
    t_type  type;
    t_token *list;

    i = 0;
    list = NULL;
    while (cmd[i] != '\0')
    {
        while (find_space(cmd[i]))
            i++;
        start = i;
        type = token_type(cmd, i);
        i = type_index(type, cmd, i);
        array = data_array(cmd, start, i);
        add_node(&list, array, type);
    }
    print_token_list(list);
    free_list(list);
}