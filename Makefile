# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 17:52:23 by hbelle            #+#    #+#              #
#    Updated: 2024/02/29 13:36:21 by hbelle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

NAME_BONUS	=

SRCS	=	main.c \
		srcs/parses/ft_check_args.c \
		srcs/parses/ft_check_map_file.c \
		srcs/utils/ft_error_handle.c \
		srcs/data/ft_map_into_array.c \
		srcs/parses/ft_check_map_content.c \
		srcs/parses/ft_check_texture.c \
		srcs/utils/ft_function.c \
		srcs/utils/ft_init.c \
		srcs/parses/ft_access_texture.c \

SRCS_BONUS =

OBJ_DIR = .o
OBJTS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJTS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:%.c=%.o))
LIBFT	=	libft/libft.a

RM	=	rm -f
HEADER =	-I includes 
LIBS =	-Llibft/ -lft

CFLAGS = -Wall -Wextra -Werror -g

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@cc $(CFLAGS) $(HEADER) -c  $< -o $@
	@if test -s $*.c; then\
			echo "\033[01m\033[35mCompiling ⌛\033[00m\
			\033[36m$*.c\033[032m  [OK] ✅ \033[00m";\
			else \
			echo "\033[01m\033[33mCompiling \033[00m\
			\033[36m$*.c\033[00m\  [Error] ❌ \033[00m"; fi

$(NAME): $(OBJTS) $(LIBFT)
	@cc -o $(NAME) $(OBJTS) $(CFLAGS) $(HEADER) $(LIBS) minilibx-linux/libmlx.a -lSDL2
	@echo "\033[01m\033[4;33mCompilation done\033[00m\033[1;31m =▶\033[00m\033[1;32m ./${NAME}\033[00m"

$(LIBFT):
	@make -C libft/ -s

all:	${NAME}

bonus: $(OBJTS_BONUS) $(LIBFT)
	@cc -o $(NAME_BONUS) $(OBJTS_BONUS) $(LIBS) $(CFLAGS) $(HEADER)
	@echo "\033[01m\033[4;33mCompilation done\033[00m\033[1;31m -->\033[00m\033[1;32m ${NAME_BONUS}\033[00m"

clean:
	@${RM} -r $(OBJ_DIR) 
	@echo "\033[01m\033[31mRemoving objects ...\033[00m"
	@make -C libft/ fclean -s

fclean:	clean
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "\033[01m\033[31mRemoving exec : ${NAME} ...\033[00m"

re:	fclean $(LIBFT) all

.PHONY: all clean fclean re bonus
