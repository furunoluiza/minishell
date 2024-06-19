/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:08:20 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/18 14:08:23 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char    create_prompt(void)
{
    char    *prompt;

    cmd = readline(PROMPT);
    if (!cmd)
        break;
    if (cmd)
        add_history(cmd);
    free (cmd);
}

int main(int argc, char **argv, char **envp)
{  
    (void) argv;
    (void) envp;
    prompt = "minishell"
    if (argc != 1)
        return (error_messages(ARGC_ERROR));
    while (42)
    {
        create_prompt();
    }
}