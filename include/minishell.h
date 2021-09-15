#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>

# include "../libft/libft.h"
# include "parsing.h"
# include "struct.h"
# include "utils.h"

# define CHEVRON_LL '<' * '<'
# define CHEVRON_RR '>' * '>'
# define PIPE_PIPE '|' * '|'
# define AND_AND '&' * '&'

t_global	g_global;

void    print_working_directory(t_command *cmd);


#endif