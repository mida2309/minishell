/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:06 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/11 15:02:53 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//idem que le out

int	change_in(t_ast *node, int *fd_redir, t_list *envlist)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd_redir[1]);
		dup2(fd_redir[0], 0);
		close(fd_redir[0]);
		node->exec(node, envlist);
		exit(1);
	}
	return (pid);
}

//creation du file fils grace a fork 
//ferme le file descriptor le duplique et ferme et quit

int	change_out(t_ast *node, int *fd_redir, t_list *envlist)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd_redir[0]);
		dup2(fd_redir[1], 1);
		close(fd_redir[1]);
		node->exec(node, envlist);
		exit(1);
	}
	return (pid);
}

//check si il y a des pipe 
// pipe a droite et gauche 
//ferme le redir 0 et 1
//waitpid attend que le fils change detat

void	pipe_exec(t_ast *self, t_list *envlist)
{
	int	fd_redir[2];
	int	left_pid;	
	int	right_pid;
	int	pipe_check;

	pipe_check = pipe(fd_redir);
	if (pipe_check == -1)
		exit(1);
	right_pid = change_out(self->right, fd_redir, envlist);
	left_pid = change_in(self->left, fd_redir, envlist);
	close(fd_redir[0]);
	close(fd_redir[1]);
	waitpid(right_pid, NULL, 0);
	waitpid(left_pid, NULL, 0);
}	
