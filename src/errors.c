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

int error_messages(int error)
{
    ft_putstr_fd(RED"Error!\n", 2);
    if (error == -1)
        ft_putstr_fd(WHITE"\tUsage:"ORANGE"./minishell\n", 2);
    return(error);
}
