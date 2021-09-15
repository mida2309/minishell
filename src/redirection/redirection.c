/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:27:23 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 15:27:25 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool try_multi(t_cmd **cmd, int *i)
{
    int save_i;
    int end;
    int f_out;
    int j;

    save_i = *i;
    end = -1;
    f_out = -1;
    j = 0;
    while (j++ <= 1)
        if (!exec_multi(cmd, &save_i, &end, &f_out))
            return (false);
    multi_pipe(cmd, i, end, f_out);
}
static bool try_simple(t_cmd **cmd, int *i)
{
    if (cmd[*i + 1] && cmd[*i + 1]->type == '|')
    {
        multi_pipe(cmd, i, -1, -1);
        return (false);
    }
    else if (cmd[*i + 1]
        && (cmd[*i + 1]->tye == CHEVRON_RR || cmd[*i + 1]->type =='>'))
    {
        if (!red_right(cmd, i))
            return (false);
    }
    else if (cmd[*i + 1]
            && (cmd[*i + 1]->type == CHEVRON_LL || cmd[*i + 1]->type == '<'))
        red_left(cmd, i);
    return (true);
}


static bool redirection(t_cmd **cmd, int *i)
{
    if (is_simple(cmd, i))
    {
        if (!try_simple(cmd, i))
            return (false);
    }
    else if (!is_simple(cmd, i))
    {
        if (!try_multi(cmd, i))
            return (false);
    }
    return (true);

}
void    try_cmommand(t_cmd **cmd)
{
    char **av;
    int     i;

    i = 0;
    while (cmd[i])
    {
        if (cmd[i + 1] && cmd[i + 1]->type)
        {
            if (!redirection(cmd, &i))
                continue ;
            if (!cmd[i])
                break ;
        }
        else if (cmd[i]->str)
        {
            av = cmd[i]->args;
            if (count_array(av) > 0)
                update_env("_", av[count_array(av) - 1]);
            try_exec(av);
        }
        i++;
    }
}
