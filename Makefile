# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 16:55:41 by sbeylot           #+#    #+#              #
#    Updated: 2022/08/22 10:03:49 by sbeylot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASE INFO
NAME		=	fdf
NAME_BONUS	=	fdf_bonus
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

# SRCS
SRCS_NAME	=	main.c\
				error.c\
				parsing.c\
				clean.c\
				utils.c\
				fdf.c\
				hooks.c\
				drawing.c\
				point.c\
				utils2.c


SRCS_DIR	=	srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))

# OBJS
OBJS_DIR	=	objs/
OBJS		=	$(SRCS_NAME:%.c=$(OBJS_DIR)%.o)

# LIBFT
LIBFT_INC	=	-L./libft
LIBFT_A		=	-lft
LIBFT		=	$(addprefix $(LIBFT_INC) , $(LIBFT_A))

# MLX
MLX_INC		=	-L./mlx
MLX_A		=	-lmlx -lXext -lX11 -lm
MLX			=	$(addprefix $(MLX_INC) , $(MLX_A))

RED 		=	\033[0;31m
GREEN 		=	\033[0;32m
NONE 		=	\033[0m

all: info compile_libft compile_mlx $(NAME)
	@echo "\t\t[ $(GREEN)✓$(NONE) ] fdf ready!"

compile_libft:
	@make -C ./libft --no-print-directory

compile_mlx:
	@echo "\t\t[...] mlx creation..."
	@make -C ./mlx --no-print-directory
	@echo "\t\t[ $(GREEN)✓$(NONE) ] mlx ready!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) 

debug: info 
	@$(CC) $(SRCS) -o $(NAME) $(LIBFT) $(MLX) -g3 -pg
	@echo "\t\t[ $(GREEN)✓$(NONE) ] fdf for GDB ready!"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: info compile_libft compile_mlx $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME_BONUS) $(LIBFT) $(MLX)
	@echo "\t\t[ $(GREEN)✓$(NONE) ] fdf_bonus ready!"

clean:
	@make clean -C ./libft --no-print-directory
	@make clean -C ./mlx --no-print-directory
	@rm -rf $(OBJS_DIR)
	@echo "\t\t[ $(RED)✗$(NONE) ] objs/ directory"

fclean: clean
	@make fclean -C ./libft --no-print-directory
	@rm -f $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "\t\t[ $(GREEN)✓$(NONE) ] Project clean"

re: fclean all

.PHONY: all clean fclean re info header compile_mlx compile_libft



info: header

define HEADER 
  ______ _____  ______   _ _       _                _       _   
 |  ____|  __ \|  ____| | | |     | |              | |     | |  
 | |__  | |  | | |__    | | |  ___| |__   ___ _   _| | ___ | |_ 
 |  __| | |  | |  __|   | | | / __| '_ \ / _ \ | | | |/ _ \| __|
 | |    | |__| | |      | | | \__ \ |_) |  __/ |_| | | (_) | |_ 
 |_|    |_____/|_|      | | | |___/_.__/ \___|\__, |_|\___/ \__|
                        | | |                  __/ |            
                        |_|_|                 |___/

endef
export HEADER

header:
	@clear
	@echo "$$HEADER"
