# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2020/03/18 23:43:30 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_FOLDER	= ../
BUF_OPT	= -D BUFFER_SIZE=
BUF_SZ	= 20
BUF_SZS	= 1 2 5 6 20 25 1024 5000 9999 10000000
ALLTESTS = $(addprefix buff, $(BUF_SZS))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f
VARS	= $(BUF_OPT)$(BUF_SZ)
COMPL	= $(CC) $(CFLAGS) -o $(NAME) $(SRCS) main*.c

NAME	= ./a.out

FILES	= get_next_line.c get_next_line_utils.c
SRCS	= $(addprefix $(GNL_FOLDER), $(FILES))

all:		$(NAME)

$(NAME):
			@$(COMPL) $(VARS)
			@echo "\033[1m\033[38;5;11m \nTest: $(BUF_OPT)$(BUF_SZ) \033[0m"
			@./$(NAME)

tests: $(ALLTESTS) fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

buff1:
			@$(COMPL) $(BUF_OPT)1
			@sh testing.sh "$(NAME)" "1"
buff2:
			@$(COMPL) $(BUF_OPT)2
			@sh testing.sh "$(NAME)" "2"
buff5:
			@$(COMPL) $(BUF_OPT)5
			@sh testing.sh "$(NAME)" "5"
buff6:
			@$(COMPL) $(BUF_OPT)6
			@sh testing.sh "$(NAME)" "6"
buff20:
			@$(COMPL) $(BUF_OPT)20
			@sh testing.sh "$(NAME)" "20"
buff25:
			@$(COMPL) $(BUF_OPT)25
			@sh testing.sh "$(NAME)" "25"
buff1024:
			@$(COMPL) $(BUF_OPT)1024
			@sh testing.sh "$(NAME)" "1024"
buff5000:
			@$(COMPL) $(BUF_OPT)5000
			@sh testing.sh "$(NAME)" "5000"
buff9999:
			@$(COMPL) $(BUF_OPT)9999
			@sh testing.sh "$(NAME)" "9999"
buff10000000:
			@$(COMPL) $(BUF_OPT)10000000
			@sh testing.sh "$(NAME)" "10000000"

.PHONY:		all clean fclean re
