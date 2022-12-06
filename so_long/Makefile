# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 16:09:33 by hmorales          #+#    #+#              #
#    Updated: 2022/12/06 15:59:50 by hmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	so_long.c \
			map_render.c \
			map_render2.c \
			map_stuff.c \
			matrix_stuff.c \
			character.c \
			movements.c \
			img_loader.c \
			algorithm.c \
			algorithm2.c \

FLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -O3#  -save-temps   

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	./libft/libft.a

MLX		=	./mlx/libmlx.a

CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(LIBFT)
	$(CC)  $(FLAGS) $(OBJS) -Iincludes $(LIBFT)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make -C ./libft/
	
$(MLX):
	@make -C ./mlx/

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"	
	@make fclean -C ./libft/

fclean: clean
	@rm -rf $(NAME)

re: fclean all
