# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2021/03/07 19:24:20 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_FOLDER	= ../get_next_line
BUF_OPT	= -D BUFFER_SIZE=
BUF_SZ	= 20
BUF_SZS	= 1 2 5 6 20 25 1024 5000 9999 10000000
ALLTESTS = $(addprefix buf, $(BUF_SZS))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f
VARS	= $(BUF_OPT)$(BUF_SZ)
LIMITS	= -D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
COMPL	= $(CC) $(CFLAGS) -o $(NAME) $(SRCS) main.c $(LIMITS)

NAME	= a.out

FILES	= get_next_line.c get_next_line_utils.c
SRCS	= $(addprefix $(GNL_FOLDER), $(FILES))

all:		$(NAME)

$(NAME):
			@$(COMPL) $(VARS)
			@echo "\033[1m\033[38;5;11m \nTest: $(BUF_OPT)$(BUF_SZ)\n \033[0m"
			@./$(NAME)

tests: $(ALLTESTS) fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

buf1:
			@$(COMPL) $(BUF_OPT)1
			@sh testing.sh "$(NAME)" "1"
buf2:
			@$(COMPL) $(BUF_OPT)2
			@sh testing.sh "$(NAME)" "2"
buf5:
			@$(COMPL) $(BUF_OPT)5
			@sh testing.sh "$(NAME)" "5"
buf6:
			@$(COMPL) $(BUF_OPT)6
			@sh testing.sh "$(NAME)" "6"
buf20:
			@$(COMPL) $(BUF_OPT)20
			@sh testing.sh "$(NAME)" "20"
buf25:
			@$(COMPL) $(BUF_OPT)25
			@sh testing.sh "$(NAME)" "25"
buf1024:
			@$(COMPL) $(BUF_OPT)1024
			@sh testing.sh "$(NAME)" "1024"
buf5000:
			@$(COMPL) $(BUF_OPT)5000
			@sh testing.sh "$(NAME)" "5000"
buf9999:
			@$(COMPL) $(BUF_OPT)9999
			@sh testing.sh "$(NAME)" "9999"
buf10000000:
			@$(COMPL) $(BUF_OPT)10000000
			@sh testing.sh "$(NAME)" "10000000"

.PHONY:		all clean fclean re
