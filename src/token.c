/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:33:46 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/26 15:33:49 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int  type_index(t_type type, char *cmd, int i)
{
    if (type == HEREDOC || type == APPEND || type == FLAG)
        i += 2;
    else if (type == ENV_VAR)
        i = index_envvar(cmd, i);
    else if (type == SINGLE_QUOTE)
        i = index_single(cmd, i);
    else if (type == DOUBLE_QUOTE)
        i = index_double(cmd, i);
    else if (type == CMD)
        i = index_cmd(cmd, i);
    else
        i++;
    return (i);
}

t_token    *tokenizator(char *cmd)
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
    return(list);
}