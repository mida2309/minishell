/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:20:05 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 16:20:06 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool simple_pipe(t_cmd **cmd, int *j)
{
    int i;

    i = *j;
    while (cmd[i + 1] && cmd[i + 1]->type == '|')
        i++;
    if (cmd[i + 1] && cmd[i + 1]-> type != '|')
        return (false);
    return (true);
}

static bool simple_left(t_cmd **cmd, int *j)
{
    int i;

    i = *j;
    while (cmd[i + 1]
		&& (cmd[i + 1]->type == CHEVRON_LL || cmd[i + 1]->type == '<'))
        i++;
    if (cmd[i + 1]
        && (cmd[i + 1]->type != CHEVRON_LL || cmd[i + 1]->type != '<'))
        return (false);
    return (true);
    
}

static bool simple_right(t_cmd **cmd, int *j)
{
    int i;

    i = *j;
    while (cmd[i + 1]
        && (cmd[i + 1]->type == CHEVRON_RR || cmd[i + 1]->type == '>'))
        i++;
    if (cmd[i + 1]
        && (cmd[i + 1]->type != CHEVRON_RR || cmd[i + 1]->type != '>'))
        return (false);
    return (true);
}

bool is_simple(t_cmd **cmd, int *j)
{
    int i;

    i = *j;
    if (cmd[i + 1] && cmd[i + 1]->type == '|')
    {
        if (!simple_pipe(cmd, &i))
            return (false);
    }
    else if (cmd[i + 1]
        && (cmd[i + 1]->type == CHEVRON_RR || cmd[i + 1]->type == '>'))
    {
        if (!simple_right(cmd, &i))
            return (false);
    }
    else if (cmd[i + 1]
        && (cmd[i + 1]->type == CHEVRON_LL || cmd[i + 1]->type == '<'))
    {
        if (!simple_left(cmd, &i))
            return (false);
    }
    return (true);
}
