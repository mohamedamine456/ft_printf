# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 19:42:53 by mlachheb          #+#    #+#              #
#    Updated: 2019/12/01 20:05:17 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf.h ft_printf_helpers.c\
	  convert/flags_trait.c convert/ft_char_convert.c\
	  convert/ft_helping_functions.c convert/ft_hexa_convert.c\
	  convert/ft_int_convert.c convert/ft_pointer_convert.c\
	  convert/ft_sint_convert.c convert/ft_string_convert.c convert/ft_unsint_convert.c\
	  libft/ft_addchar.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isflag.c\
	  libft/ft_isformat.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_memset.c libft/ft_nsize.c\
	  libft/ft_putstr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c\
	  libft/ft_strrev.c libft/ft_substr.c

OBJSRC = ft_printf.o ft_printf_helpers.o\
		 flags_trait.o ft_char_convert.o\
		 ft_helping_functions.o ft_hexa_convert.o\
		 ft_int_convert.o ft_pointer_convert.o\
		 ft_sint_convert.o ft_string_convert.o ft_unsint_convert.o\
		 ft_addchar.o ft_atoi.o ft_isdigit.o ft_isflag.o\
		 ft_isformat.o ft_itoa.o ft_memmove.o ft_memset.o ft_nsize.o\
		 ft_putstr.o ft_strdup.o ft_strjoin.o ft_strlen.o\
		 ft_strrev.o ft_substr.o

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
