/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:21 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:31:31 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//list ajout arriere ajout la fin malloc content return res
t_list	*converter(char **envp)
{
	int		i;
	t_list	*head;

	head = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
	return (head);
}
