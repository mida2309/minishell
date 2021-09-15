/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:31:09 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 14:31:11 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool try_create_cmd(char **strp, t_parsing *parsing, t_cmd ***cmdsp, int *i)
{
    int type;
    char *str;

    str = *strp;
    if (!parsing->inhibited && !parsing->single_q && !parsing->double_q 
        && ft_is_in_set(*str, "<>|;&"))
    {
        add_calloc(cmdsp);
        (*i)++;
        type = *str;
        if (double_char(*str, *(str + 1), "<>|&"))
        {
            type *= type;
            (*strp)++;
        }
        (*cmdsp)[*i]->type = type;
        return (true);
    }
    return (false);
}

static void put_args(t_cmd **cmd)
{
    int i;

    if (!cmd)
        return ;
    i = -1;
    while (cmd[i]->str)
    {
        if (cmd[i]->str)
            cmd[i]->args = parsing(cmd[i]->str);
    }
}


t_cmd   **split_cmd(char *str)
{
    t_cmd       **cmd;
    t_parsing   parsing;
    int         i;

    i = 0;
    cmd = ft_calloc(2, sizeof(t_cmd *));
    cmd[i] = ft_calloc(1, sizeof(t_cmd));
    parsing = (t_parsing){0};
    while (*str)
    {
        update_struct2(*str, &parsing);
        if (!try_create_cmd(&str, &parsing, &cmd, &i))
            add_char(&cmd[i]->str, *str);
        str++;
    }
    if (!command_valid(cmd))
    {
        free_command(cmd);
        return (NULL);
    }
    put_args(cmd);
    return (cmd);
}
