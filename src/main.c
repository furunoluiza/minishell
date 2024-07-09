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
    t_token *token;

    if (argc != 1)
        return (error_messages(ARGC_ERROR, NULL));
    while (42)
    {
        cmd = readline("minishell$ ");
        if (!cmd)
            cmd = ft_strdup("exit");
        if (*cmd)
        {
            add_history(cmd);
            token = tokenizator(cmd);
            parsing(token);
            free_list(token);
        }
    }
    rl_clear_history();
    return(0);
}