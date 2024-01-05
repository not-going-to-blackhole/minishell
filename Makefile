# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:56:33 by woorikim          #+#    #+#              #
#    Updated: 2024/01/05 14:12:58 by woorikim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L /opt/homebrew/opt/readline/lib -lreadline
CPPFLAGS = -I /opt/homebrew/opt/readline/include

LIBRARY = libft/libft.a

SRC = main.c reading.c token_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) LIBRARY
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(LDFLAGS) $(CFALG)

LIBRARY :
	make -C libft

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re