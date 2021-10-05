# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 23:31:12 by idamouttou        #+#    #+#              #
#    Updated: 2021/10/04 23:31:22 by idamouttou       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror	
SRCS		=	srcs/main.c \
				srcs/build/cd.c srcs/build/echo.c srcs/build/env.c srcs/build/exit.c \
				srcs/build/export.c srcs/build/pwd.c srcs/build/unset.c \
				srcs/excution/exec_coms.c srcs/excution/exec_pipe.c srcs/excution/exec_redir.c \
				srcs/excution/find_exec.c \
				srcs/parsing/converter.c srcs/parsing/parser.c srcs/parsing/sig_handlers.c srcs/parsing/token_to_ast.c \
				srcs/utils/env_utils.c srcs/utils/exec_coms_utils.c srcs/utils/list_utils.c srcs/utils/parser_utils.c srcs/utils/main_utils.c
OBJS 		=	$(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
deps 		= 	$(patsubst %.o,%.d,$(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
		cd Libft/ && make && make bonus && make clean
		gcc $(CFLAGS) $(OBJS)  -o $(NAME) -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -LLibft/ -lft -L.
-include $(deps)

DEPSFLAGS 	= -MMD -MF $(@:.c=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPSFLAGS) -o $(<:.c=.o)
clean:
	rm -f $(OBJS)
	

fclean: clean 
	rm -f $(NAME)
	cd Libft/ && make fclean

re: fclean all

.PHONY: all, clean, fclean, re
