# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:00:48 by rpohlen           #+#    #+#              #
#    Updated: 2022/01/28 09:31:51 by rpohlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= $(shell find src -name '*.c')
OBJ			= $(SRC:%.c=$(OBJDIR)/%.o)
OBJDIR		= obj

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Wno-unused-result -O3 -I include/

NAME		= libft.a



$(OBJDIR)/%.o: %.c
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJ}
			ar rcs $@ $?

all:		${NAME}

clean:
			${RM} ${OBJDIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
