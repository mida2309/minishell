/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:29:33 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/15 19:05:20 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//affiche la variable denvirronement 
int	my_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		write(1, tmp->content, ft_strlen(tmp->content));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	return (0);
}
