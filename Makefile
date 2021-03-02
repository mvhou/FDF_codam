# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-hou <mvan-hou@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/07 15:50:57 by mvan-hou       #+#    #+#                 #
#    Updated: 2019/09/23 20:53:33 by mvan-hou      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME	= fdf
LIBFT	= libft/libft.a

CC		= gcc -Wall -Wextra -Werror

RED		= \033[0;31m
GREEN	= \033[0;32m
NC		= \033[0m

SRC		=	src/main.c \
			src/read.c \
			src/initialize.c \
			src/tools.c

MLX 	= -I /minilibx_macos/ -L ~/desktop/fdf/minilibx_macos/ -lmlx

GL		= -framework OpenGL -framework AppKit

OBJ		= $(SRC:%.c=%.o)

INCL	= libft

all:	$(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME):	$(OBJ) $(LIBFT)
	@echo "${GREEN}Making libftprintf.a${NC}"
	@cp libft/libft.a .
	$(CC) $(MLX) $(SRC) $(GL) -L . -lft -o $(NAME)


.PHONY: clean

clean:
	@rm -f $(OBJ)
	@echo "${RED}Cleaning object files${NC}"
	@$(MAKE) clean -C libft

lldb: re
	gcc -g main.c -L. -lftprintf

fclean:	clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft

re:	fclean all