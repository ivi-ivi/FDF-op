# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcrissy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 19:35:57 by mcrissy           #+#    #+#              #
#    Updated: 2019/09/26 20:57:35 by mcrissy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c	ft_strrchr.c ft_bzero.c ft_memdel.c ft_strcat.c ft_strstr.c ft_isalnum.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strsub.c ft_isalpha.c ft_memset.c ft_strclr.c ft_strcmp.c ft_strtrim.c ft_isascii.c ft_putchar.c ft_tolower.c ft_isdigit.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_toupper.c ft_isprint.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c ft_itoa.c ft_strsplit.c ft_strlcat.c ft_strmap.c ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRC)
	   	ar rc $(NAME) *.o
		ranlib $(NAME)

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
