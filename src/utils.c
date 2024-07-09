/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:54:09 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/24 16:54:11 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int    find_space(char cmd)
{
    if (cmd == ' ' || (cmd >= 7 && cmd <= 13))
            return (1);
    return (0);
}

void print_token_list(t_token *head) //apagar
{
    t_token *current = head;

    printf("Lista de Tokens:\n");

    while (current != NULL) {
        printf("Token: %s\n", current->data);
        printf("Tipo: %d\n",current->type);
        current = current->next;
    }
}