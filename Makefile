# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 12:11:49 by guilmira          #+#    #+#              #
#    Updated: 2023/11/27 14:58:45 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MAP 	= map3.ber
#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= soLong
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes
INCLUDES_LIBX	= -lmlx -framework OpenGL -framework AppKit
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	0so_long.c 0init_structs.c 1control_window.c \
				2map_parser.c 2map_read.c 3get_sprites.c 4background.c \
				5management.c 6loop_animation.c \
				7booleans_n_tools.c 7hook_movement.c 8image_functions.c
OBJS		= $(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(INCLUDES_LIBX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	./$(NAME) $(NAME_MAP)

norm:
	norminette $(SRCS)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'
