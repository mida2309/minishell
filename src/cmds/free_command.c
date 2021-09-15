/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:58:44 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:58:47 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    free_command(t_cmd **cmd)
{
    int i;

    if (!cmd)
        return ;
    i = -1;
    while (cmd[++i])
    {
        if (cmd[i]->str)
            free(cmd[i]->str);
        if (cmd[i]->args)
            free_array(cmd[i]->args);
        free(cmd[i]);
    }
    free(cmd);
}
