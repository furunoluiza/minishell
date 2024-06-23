#include "../include/minishell.h"

char    *make_prompt(void)
{
    char    *prompt;
    char    dir[PATH_MAX];

    prompt = getcwd(dir, sizeof(dir));
    prompt = ft_strjoin(prompt, "$>>> ");
    return (prompt);
}