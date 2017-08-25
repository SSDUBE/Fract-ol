# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdube <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 18:27:43 by sdube             #+#    #+#              #
#    Updated: 2016/10/09 18:27:47 by sdube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/main.c\
	  src/init_engine.c\
	  src/fractal.c\
	  src/fractal_sets.c\
	  src/event.c\
	  src/colorize.c\
	  src/m_events.c

MLX_OPS = -lmlx -framework AppKit -framework OpenGL

INCLUDES = -Iincludes -Ilibft/inc

all: $(NAME)

$(NAME):
	@gcc $(INCLUDES) $(SRC) $(MLX_OPS) -o $(NAME) -Llibft -lft
	@echo "Use it wisely!"

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
