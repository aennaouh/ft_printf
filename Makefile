# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 21:54:09 by aennaouh          #+#    #+#              #
#    Updated: 2022/11/19 23:04:47 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c\
ft_printf_utils.c\
ft_printf_last.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< 

$(NAME): ${OBJS}
	ar -rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
	
fclean: clean
	rm -f ${NAME}

re : fclean all  

.PHONY: all clean fclean re