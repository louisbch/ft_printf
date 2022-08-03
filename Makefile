# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 18:12:40 by lbouchon          #+#    #+#              #
#    Updated: 2022/08/03 10:38:48 by lbouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -f
CC = gcc
FLAG = -Wall -Wextra -Werror
NORMINETTE = norminette -R CheckDefine
INCLUDES = ../Libft

SRC = \
			ft_printf.c \
			ft_printstr.c \
			ft_utils.c \
			ft_printptr.c \
			ft_printstr.c \
			ft_print_hex.c \
			

SRCS = ${SRC}
OBJS = ${SRCS:.c=.o}

all = ${NAME}

${NAME} : ${OBJS}
		ar rcs $@ $^

clean :
		${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.c.o: ${SRC}
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

norm :
		${NORMINETTE}