# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:43:48 by mlachheb          #+#    #+#              #
#    Updated: 2019/11/17 10:53:55 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

OBJSRC = 

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJSRC)

fclean:
	/bin/rm -rf $(NAME)

re: fclean all
