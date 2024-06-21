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

int main(int argc, char **argv, char **envp)
{ 
    char    *cmd;
    (void) argv;
    (void) envp;

    if (argc != 1)
        return (error_messages(ARGC_ERROR));
    while (42)
    {
        cmd = readline("minishell$ ");
        if (!cmd)
            break;
        if (cmd)
        {
            add_history(cmd); //se for vazio?
            input_token(cmd);
        }
        free (cmd);
    }
    return(0);
}
