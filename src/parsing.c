/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:22:48 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/07/09 13:23:14 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int val_redirects_pipe(t_token *token)
{
    while(token && token->next != NULL)
    {
        if (token->type == REDIRECT_IN)
        {
            if (token->next->type == REDIRECT_IN || token->next->type == HEREDOC
                || token->next->type == APPEND || token->next->type == PIPE
                || token->next->type == REDIRECT_OUT)
                return(error_messages(-2, token->next));
        }
        else if (token->type == REDIRECT_OUT)
        {
            if (token->next->type == REDIRECT_IN || token->next->type == HEREDOC
                || token->next->type == APPEND || token->next->type == PIPE
                || token->next->type == REDIRECT_OUT)
                return(error_messages(-2, token->next));
        }
        else if (token->type == PIPE)
        {
            if (token->next->type == PIPE)
                return(error_messages(-2, token->next));
        }
        token = token->next;
    }
    return (0);
}
static int val_heredoc_append(t_token *token)
{
    while(token && token->next != NULL)
    {
        if (token->type == APPEND)
        {
            if (token->next->type == REDIRECT_IN || token->next->type == HEREDOC
                || token->next->type == APPEND || token->next->type == PIPE
                || token->next->type == REDIRECT_OUT)
                return(error_messages(-2, token->next));
        }
        else if (token->type == HEREDOC)
        {
            if (token->next->type == REDIRECT_IN || token->next->type == HEREDOC
                || token->next->type == APPEND || token->next->type == PIPE
                || token->next->type == REDIRECT_OUT)
                return(error_messages(-2, token->next));
        }
        token = token->next;
    }
    return (0);
}
static int val_init_end(t_token *token)
{
    if (token->type == PIPE)
        return(error_messages(-2, token));
    while(token && token->next != NULL)
        token = token->next;
    if (token->type == PIPE || token->type == APPEND || token->type == HEREDOC
        || token->type == REDIRECT_IN || token->type == REDIRECT_OUT)
        return(error_messages(-3, token));
    return (0);
}

static int val_quotes(t_token *token)
{
    int i;
    int find;
    char quote;

    while(token)
    {
        if (token->type == SINGLE_QUOTE || token->type == DOUBLE_QUOTE)
        {
            quote = token->data[0];
            find = 0;
            i = 1;
            while (token->data[i] != '\0')
            {
                if (token->data[i++] == quote)
                {
                    find = 1;
                    break ;
                }
            }
            if (!find)
                return (error_messages(-4, token));
        }
        token = token->next;
    }
    return (0);
}

int    parsing(t_token *token)
{
    if (!val_redirects_pipe(token) && !val_heredoc_append(token) 
        && !val_init_end(token) && !val_quotes(token))
            return (1);
    if (!heredoc_exist(token))
            return (1);
    return(0);
}