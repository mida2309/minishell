/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:49:52 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:49:54 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    add_calloc(t_cmd ***cmdsp)
{
    int     count;
    t_cmd   **tmp;
    t_cmd   **cmd;

    cmd = *cmdsp;
    count = -1;
    while (cmd[++count])
        ;
    tmp = ft_calloc(count + 2, sizeof(t_cmd *));
    count = -1;
    while (cmd[++count])
        tmp[count] = cmd[count];
    tmp[count] = ft_calloc(1, sizeof(t_cmd));
    free(cmd);
    *cmdsp = tmp;
}
