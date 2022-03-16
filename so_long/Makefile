# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:09:33 by hmorales          #+#    #+#              #
#    Updated: 2022/03/03 18:56:19 by hmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	so_long.c \
			map_render.c \
			map_stuff.c \
			matrix_stuff.c \
			character.c \
			movements.c \

FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	./libft/libft.a

MLX		=	./mlx/mlx.a

CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(MLX) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make -C ./libft/
	
$(MLX):
	@make -C ./mlx/

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"	
	@make fclean -C ./libft/
	@make clean -C ./mlx/

fclean: clean
	@rm -rf $(NAME)

re: fclean all

