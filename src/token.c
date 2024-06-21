#include "../include/minishell.h"

static int    find_space(char cmd)
{
    if (cmd == ' ' || (cmd >= 7 && cmd <= 13))
            return (1);
    return (0);
}

static void	add_node(t_token **list, char *array, t_type type)
{
    t_token *node;

	node = malloc(sizeof(t_token));
	node->data = array;
    node->type = type;
	node->next = *list;
	*list = node;
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

void	free_list(t_token *list)
{
	t_token	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
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

void print_token_list(t_token *head) {
    t_token *current = head;

    printf("Lista de Tokens:\n");

    while (current != NULL) {
        printf("Token: %s\n", current->data);
        printf("Tipo: %d\n",current->type);
        current = current->next;
    }
}

void    input_token(char *cmd)
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
        if (type == HEREDOC || type == APPEND)
            i += 2;
        else if (type == CMD)
        {
            while (cmd[i] && !find_space(cmd[i]))
                i++;
        }
        else
            i++;
        array = data_array(cmd, start, i);
        add_node(&list, array, type);
    }
    print_token_list(list);
}