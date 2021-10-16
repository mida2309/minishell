/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:29:50 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/15 19:05:26 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strerror Obtenir le libellé d'un numéro d'erreur  
#include "../../includes/minishell.h"

int	my_pwd(void)
{
	char	*abs_path;
	char	*res;

	abs_path = NULL;
	res = getcwd(NULL, 0); //Obtenir le répertoire de travail courant 
	if (res == NULL)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	write(1, res, ft_strlen(res));//ecrit le pwd
	write(1, "\n", 1);
	free(res);
	return (1);
}
