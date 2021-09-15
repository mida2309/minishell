/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:31:49 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:31:52 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

void	add_value(char **str, char *new_value);
void    ft_error(char *msg, char *error_msg, int error_code);
bool	ft_isutil(char *str);
void	ft_safe_free(void **p);
bool	ft_streql(const char *s1, const char *s2);
void	free_array(char **array);
#endif