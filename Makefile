# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 18:12:40 by lbouchon          #+#    #+#              #
#    Updated: 2022/08/08 12:06:24 by lbouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -f
CC = gcc
FLAGS = -Wall -Wextra -Werror
NORMINETTE = norminette -R CheckDefine

SRCS = \
			ft_printf.c \
			ft_utils.c \
			ft_printptr.c \
			ft_print_hex.c \
			ft_print_unsigned.c \
			ft_printstr.c \

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
		ar rcs $@ $^

clean :
		${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.c.o: ${SRCS}
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

norm :
		${NORMINETTE}