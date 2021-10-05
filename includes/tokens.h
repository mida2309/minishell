/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:28:24 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:31:45 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef struct s_token_lst
{
	struct s_tokens_list	*next;
	char					*token;
	int						type;
}							t_token_lst;
#endif
