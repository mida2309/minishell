/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:27:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/21 23:10:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_state	g_state;

static void	prompt(void)
{
	write(STD_OUT, "minishell-1.0$ ", 16);
}

/*
** return 0:success -1:failed 127:exit
*/

int			minishell(t_dlist **programs, t_history **history, char **envp)
{
	char		*line;

	(void)envp;
	line = NULL;
	init_term();
	while (1)
	{
		prompt();
		tcsetattr(STDIN_FILENO, TCSANOW, &g_state.term);
		g_state.need_nl = FALSE;
		set_history(history);
		if (save_input() != 1)
			continue ;
		if (save_history(history) != 1)
			continue ;
		line = ft_strdup(g_state.cur->save);
		if (check_quote(&line) != 1)
			continue ;
		restore_term();
		run_program(programs, line);
		ft_strdel(&line);
		free_program(programs);
	}
	return (0);
}

int			main(int argc, char *argv[], char *envp[])
{
	t_dlist		*programs;
	t_history	*history;

	(void)argc;
	(void)argv;
	programs = NULL;
	history = NULL;
	init_state();
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	env_parse(envp);
	minishell(&programs, &history, envp);
	free_state();
	ft_dlstclear(&programs, free);
	ft_historyclear(&history, free);
	return (g_state.ret);
}
