#include "../include/minishell.h"

int herdeoc_file(char *token)
{
    int fd;
    char    *file;

    file = ft_strdup("/tmp/heredoc");
    fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0)
		return (free(file), 0);
    heredoc(token, file, fd);
    return (1);
}

int heredoc_exist(t_token *token)
{
    while(token)
    {
        if(token->type == HEREDOC)
        {
            if (!heredoc_file(token->next))
                return (0);
        }
        token = token->next;
    }
    return (1);
} 