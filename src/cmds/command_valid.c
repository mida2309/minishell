/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:01:33 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 22:01:35 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *string_char(int nb)
{
    if (nb == CHEVRON_RR)
        return (">>");
    else if (nb == CHEVRON_LL)
        return ("<<");
    else if (nb == PIPE_PIPE)
        return ("||");
    else if (nb == AND_AND)
        return ("&&");
    else if (nb == '|')
        return ("|");
    else if (nb == '<')
        return ("<");
    else if (nb == '>')
        return (">");
    else if (nb == ';')
        return (";");
    else if (nb == '&')
        return ("&");
    return (NULL);
}

static bool first_command(t_cmd **cmd)
{
    char *str_error;

    if (cmd[1] && cmd[0]->type == 0 && cmd[0]->str == 0
        && cmd[1]->type != 0)
    {
        str_error = string_char(cmd[1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);
}

static bool double_semicolon(t_cmd **cmd, int i)
{
    char *str_error;

    if (cmd[i + 1] && cmd[i]->type == ';' && cmd[i + 1]->type == ';'
        && !cmd[i]->str)
    {
        ft_error("Synthax error", ";;", 2);
        return (false);
    }
    else if (cmd[i]->type == ';')
        cmd[i]->type = 0;
    if (cmd[i + 1] && cmd[i]->type == 0 && cmd[i + 1]->type != 0
        && (ft_streql(cmd[i]->str, " ") || !cmd[i]->str))
    {
        str_error = string_char(cmd[i + 1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);
}

static bool double_separator(t_cmd **cmd, int i)
{
    char *str_error;

    if (cmd[i + 1] && cmd[i]->type != 0
        && (ft_streql(cmd[i]->str, " ") || !cmd[i]->str))
    {
        str_error = string_char(cmd[i + 1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);

}

bool command_valid(t_cmd **cmd)
{
    int i;

    i = -1;
    if (!first_command(cmd))
        return (false);
    while (cmd[++i])
    {
        if (cmd[i]->type == 0)
            continue ;
        if (!double_semicolon(cmd, i)
            || !double_separatot(cmd, i))
                return (false);
    }
    if (!cmd[i - 1]->str && cmd[i - 1]->type)
    {
        printf("Error\n");
        return (false);
    }
    return (true);
}