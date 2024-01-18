# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:56:33 by woorikim          #+#    #+#              #
#    Updated: 2024/01/18 10:52:53 by woorikim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

# woorikim's m1
LDFLAGS = -L /opt/homebrew/opt/readline/lib -lreadline
CPPFLAGS = -I /opt/homebrew/opt/readline/include

# cluster's MAC
#  LDFLAGS = -L $(HOME)/.brew/opt/readline/lib -lreadline
#  CPPFLAGS = -I $(HOME)/.brew/opt/readline/include

LIBRARY = libft/libft.a

SRC = main.c reading.c
		
SRC_BUILTIN = srcs/builtin/builtin_echo.c srcs/builtin/builtin_pwd.c srcs/builtin/builtin_cd.c  \
		srcs/builtin/builtin_export.c srcs/builtin/builtin_unset.c srcs/builtin/builtin_env.c \
		srcs/builtin/utils.c srcs/cmd_list/cmd_memory_management.c srcs/execution/heredoc_processor.c \
		srcs/execution/mini_execution.c srcs/execution/set_heredoc_fd.c
		
SRC_PARSING = parsing/token_utils.c parsing/env_utils.c parsing/do_lexical.c parsing/check_heredoc.c \
		parsing/parsing_utils.c parsing/check_quotation.c parsing/split_quotation.c \
		parsing/check_env.c parsing/split_env.c parsing/parse_by_delimiter.c parsing/do_syntax.c \
		parsing/parse_cmds.c 

SRC_SIGNAL = signal/setting_signal.c \

TEST_SRC = tmp/parsing_test.c

OBJ = $(SRC:.c=.o) $(SRC_BUILTIN:.c=.o) $(SRC_PARSING:.c=.o) $(SRC_SIGNAL:.c=.o)
#OBJ = $(SRC:.c=.o) $(TEST_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) LIBRARY
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(LDFLAGS)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

LIBRARY :
	make -C libft

clean :
	rm -f $(OBJ)
	make clean -C libft
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re : fclean all

.PHONY : all clean fclean re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m