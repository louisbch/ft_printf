# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 18:12:40 by lbouchon          #+#    #+#              #
#    Updated: 2022/08/03 12:50:13 by lbouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -f
CC = gcc
FLAG = -Wall -Wextra -Werror
NORMINETTE = norminette -R CheckDefine

SRC = \
			ft_printf.c \
			ft_printstr.c \
			ft_utils.c \
			ft_printptr.c \
			ft_printstr.c \
			ft_print_hex.c \
			ft_print_unsigned.c \
			

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