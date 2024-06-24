/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:53:52 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/24 16:53:54 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char    *make_prompt(void)
{
    char    *prompt;
    char    *directory;
    char    dir[PATH_MAX];

    directory = getcwd(dir, sizeof(dir));
    prompt = ft_strjoin(directory, "$>>> ");
    free(directory);
    directory = NULL;
    return (prompt);
}
