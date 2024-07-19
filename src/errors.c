/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:51:53 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/18 17:52:00 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int error_messages(int error, t_token *token)
{
    ft_putstr_fd(RED"Error: ", 2);
    if (error == -1)
        ft_putstr_fd(WHITE"\tUsage:"ORANGE"./minishell\n", 2);
    else if (error == -2)
    {
        ft_putstr_fd(WHITE"syntax error near unexpected token `", 2);
        ft_putstr_fd(token->data, 2);
        ft_putstr_fd("\'\n", 2);
    }
    else if (error == -3)
        ft_putstr_fd(WHITE"syntax error near unexpected token `newline'\n", 2);
    else if (error == -4)
        ft_putstr_fd(WHITE"only parses closed quotes\n", 2);
    return(error);
}
