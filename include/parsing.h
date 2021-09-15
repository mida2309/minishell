/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:56:36 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:34:32 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <stdbool.h>
 //parsing

typedef struct s_parsing
{
	bool	inhibited;
	bool	single_q;
	bool	double_q;
	bool	sp;
	bool	is_inhiber;
	bool	is_simple;
	bool	is_double;
}	t_parsing;
 
char	**parsing(char *str);
bool	ft_valid(char *str);
void	update_struct(char c, t_parsing *parsing);
void	update_struct2(char c, t_parsing *parsing);
void    type_args(char **args, const char *set);
bool	is_inhibited(const char *str, int char_index);
int     count_args(char *str);
void 	remove_quote(char **args);
void    remove_blackslash(char **args);
void	ft_replace_str(char **args, unsigned int start_index, unsigned int end_index, char *value);
void 	split_args(char **args, char *str);
void	add_char(char **str, char c);
void	add_arg(char **args, char **tmp);
void	sub_env(char **args);
char	*ft_getenv(char *str);
void 	sub_q(char **args);
void    sub_tilde(char **args);

//command

typedef struct s_cmd
{
	int end;
	int type;
	char *str;
	char **args;

} t_cmd;


bool 	command_valid(t_cmd **cmd);
void    add_calloc(t_cmd ***cmdsp);
bool    double_char(char c, char next_c, char *set);
void    free_command(t_cmd **cmd);
bool 	ft_is_in_set(char c, const char *set);
t_cmd   **split_cmd(char *str);

// redirection 



#endif