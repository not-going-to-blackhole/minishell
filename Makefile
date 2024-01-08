# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeeun <yeeun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:56:33 by woorikim          #+#    #+#              #
#    Updated: 2024/01/08 13:01:26 by yeeun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L /opt/homebrew/opt/readline/lib -lreadline
CPPFLAGS = -I /opt/homebrew/opt/readline/include

LIBRARY = libft/libft.a

SRC = main.c reading.c token_utils.c builtin_echo.c builtin_pwd.c builtin_cd.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) LIBRARY
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(LDFLAGS) $(CFALG)
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