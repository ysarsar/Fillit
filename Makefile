# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysarsar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/18 01:06:26 by ysarsar           #+#    #+#              #
#    Updated: 2018/12/02 03:05:36 by ysarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = fillit
all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c *.c libft/*.c
	gcc *.o $(FLAGS)  -o $(NAME) 
clean :
	rm -f *.o
	rm -f libft/*.o
fclean :
	make clean
	rm -f *.o
	rm -f ./fillit ./fillit.a
	rm -f ./libft/libft.a
re : fclean all
