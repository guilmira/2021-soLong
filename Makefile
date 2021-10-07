# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 12:11:49 by guilmira          #+#    #+#              #
#    Updated: 2021/10/07 12:31:22 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes
INCLUDES_LIBX	= -lmlx -framework OpenGL -framework AppKit
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	0so_long.c 0init_structs.c 0map_parser.c 1control_window.c 1hooks_window.c \
				2image_functions.c 3get_sprites.c 4background.c \
				5management.c 6loop_animation.c 7booleans.c 7hook_movement.c
#SRCS		= 0so_long_snake.c ft_draw.c
SRCS_AUX	= ./0test/aux_keycode.c
OBJS		= $(SRCS:.c=.o)
OBJS_AUX	= $(SRCS_AUX:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

#%.o: %.c
#-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(INCLUDES_LIBX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	./$(NAME)

key: $(OBJS_AUX)
	$(CC) $(CFLAGS) $(OBJS_AUX) $(INCLUDES) $(LIB) $(INCLUDES_LIBX) -o aux_keycode
	./aux_keycode

#$(NAME): $(OBJS)
#$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) -o $(NAME)
#@echo "'$(NAME)' is now compiled."

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
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
GREEN='\033[1;32m'
