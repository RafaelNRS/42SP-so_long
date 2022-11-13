# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by ranascim          #+#    #+#              #
#    Updated: 2022/11/13 11:10:05 by ranascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
FILES_NAMES			= ft_check_map_tiles.c \
						 			ft_create_imgs.c \
						 			ft_create_map.c \
						 			ft_create_window.c \
						 			ft_destroy_display.c \
						 			ft_destroy_imgs.c \
						 			ft_destroy_matrix.c \
						 			ft_exit.c \
						 			ft_get_map_size.c \
						 			ft_message.c \
						 			ft_movement.c \
						 			ft_set_map_matrix.c \
						 			ft_valid_tiles.c \
                  					ft_validate_extension.c \
									ft_validate_map.c \
									handle_destroy_window.c \
									handle_keyrelease.c \
									render.c 

SRC_DIR 	= src/

OBJ_DIR 			= obj/

OBJ 			= $(FILES_NAMES:%.c=$(OBJ_DIR)%.o)

NAME 				= so_long

NAME_LIB 				= so_long.a

vpath %.c $(SRC_DIR)

LIBRARY_PATH		= ./libft
LIB_NAME 				= libft.a
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a

INCLUDE_PATH 				= include

MAIN_FILE 			= $(SRC_DIR)main.c

all: $(NAME)

$(NAME): $(NAME_LIB)
	$(CC) $(CFLAGS) -g $(MAIN_FILE) -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME_LIB) $(LIBFT_FILE) -lmlx -lX11 -lXext -o $(NAME)

$(NAME_LIB): $(LIB_NAME) $(OBJ)
		ar -rc $(NAME_LIB) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) -o $@ 

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ_DIR)*.o

fclean: clean
	rm -f $(NAME_LIB)
	rm -f $(LIB_NAME)
	rm $(NAME)

re: fclean all

$(LIB_NAME):
	$(MAKE) all -C $(LIBRARY_PATH)
	cp $(LIBFT_FILE) $(LIB_NAME)

libclean:
	$(MAKE) clean -C $(LIBRARY_PATH)

libfclean:
	$(MAKE) fclean -C $(LIBRARY_PATH)
	rm -f $(LIB_NAME)

libre:
	$(MAKE) re -C $(LIBRARY_PATH)

run: so_long
	@./so_long ./maps/map1.ber
