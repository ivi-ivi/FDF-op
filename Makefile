# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcrissy <mcrissy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:52:58 by mcrissy           #+#    #+#              #
#    Updated: 2020/02/19 17:08:31 by mcrissy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBS = -lmlx -lm -lft -L$(LIBFT_D) -L$(MINILIBX_D) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_D) -I$(LIBFT_H) -I$(MINILIBX_H)

MINILIBX = $(MINILIBX_D)libmlx.a
MINILIBX_D = ./minilibx_macos/
MINILIBX_H = $(MINILIBX_D)

C = gcc
FLAGS = -Wall -Wextra -Werror 

HEAD = fdf.h color.h get_next_line.h
HEADERS_D = ./includes/
HEADERS = $(addprefix $(HEADERS_D), $(HEAD))

LIBFT = $(LIBFT_D)libft.a
LIBFT_D = ./libft/
LIBFT_H = $(LIBFT_D)includes/

SRCS = ./src/
SRC = main.c act.c color_more.c color.c dop.c draw.c get_next_line.c keyboard.c lines.c list_struct.c mouse.c projections.c rotation.c view.c 
S = $(addprefix $(SRCS), $(SRC))

OBJ = objects/
O = $(patsubst %.c, %.o, $(SRC))
OBJECTS	= $(addprefix $(OBJ), $(O))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ) $(OBJECTS)
	@$(C) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)%.o : $(SRCS)%.c $(HEADERS)
	@$(C) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_D)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_D)

clean:
	@$(MAKE) -sC $(LIBFT_D) clean
	@$(MAKE) -sC $(MINILIBX_D) clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all