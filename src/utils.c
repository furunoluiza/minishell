#include "../include/minishell.h"

int    find_space(char cmd)
{
    if (cmd == ' ' || (cmd >= 7 && cmd <= 13))
            return (1);
    return (0);
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

void print_token_list(t_token *head) 
{
    t_token *current = head;

    printf("Lista de Tokens:\n");

    while (current != NULL) {
        printf("Token: %s\n", current->data);
        printf("Tipo: %d\n",current->type);
        current = current->next;
    }
}