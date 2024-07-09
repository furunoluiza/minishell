/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:17:58 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/06/18 14:18:00 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* -- LIBS -- */
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free, null
# include <readline/readline.h> //readline
# include <readline/history.h> //add_history

/* -- COLORS -- */
# define RED	"\001\033[38;2;255;0;0m\002"
# define GREEN	"\001\033[38;2;0;255;0m\002"
# define BLUE	"\001\033[38;2;0;0;255m\002"
# define YELLOW	"\001\033[38;2;255;255;0m\002"
# define WHITE	"\001\033[38;2;255;255;255m\002"
# define ORANGE	"\001\033[38;2;255;165;0m\002"
# define PURPLE	"\001\033[38;2;153;51;153m\002"

/* -- STRUCTS -- */
typedef enum s_type
{
    CMD, //0
    ARG, //1
    REDIRECT_IN, //2
    REDIRECT_OUT, //3
    PIPE, //4
    HEREDOC, //5
    APPEND, //6
    FLAG, //7
    ENV_VAR, //8
    SINGLE_QUOTE, //9
    DOUBLE_QUOTE, //10
}   t_type;

typedef struct s_token
{
    char    *data;
    t_type  type;
    struct s_token   *next;
}   t_token;

/* -- ERRORS -- */
/* defines errors */
# define ARGC_ERROR -1
# define SYNTAX_ERROR -2
# define NEWLINE_ERROR -3
/* functions*/
int error_messages(int error, t_token *token);

/* -- TOKEN -- */
t_token    *tokenizator(char *cmd);
t_type  token_type(char *cmd, int i);
int     index_envvar(char *cmd, int i);
int     index_single(char *cmd, int i);
int     index_double(char *cmd, int i);
int     index_cmd(char *cmd, int i);
void    print_token_list(t_token *head); //apagar

/* -- PARSING -- */
int    parsing(t_token *token);

/* -- BUILTINS -- */

/* -- FREE -- */
void    set_null(char *str);
void	free_list(t_token *list);

/* -- UTILS -- */
int     find_space(char cmd);


# endif