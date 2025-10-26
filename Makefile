# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 16:19:26 by tchartie          #+#    #+#              #
#    Updated: 2025/10/26 16:19:26 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME				= 	libasm.a

#========= COMPILATOR =========#

CC 				= 	nasm

#=========== FLAGS ============#

ASMFLAGS 		= 	

MAKEFLAGS		=	--no-print-directory

#=========== COLOR ============#

BASE_COLOR 		=	\033[0;39m
GRAY 				=	\033[0;90m
RED 				=	\033[0;91m
GREEN 			=	\033[0;92m
YELLOW 			=	\033[0;93m
BLUE 				=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN 				=	\033[0;96m
WHITE				=	\033[0;97m

#========== SOURCES ===========#

SRC_DIR 			=	src/
SRC_NAMES 		=	

SRC_NAMES_B		=

SRC 				=	$(addprefix $(SRC_DIR), $(SRC_NAMES))
SRC_BONUS		=	$(addprefix $(SRC_DIR), $(SRC_NAMES_B))

OBJ_DIR 			= 	obj/
OBJ_NAME 		= 	$(SRC_NAMES:.c=.o)
OBJ_NAME_B		=	$(SRC_NAMES_B:.c=.o)
OBJ 				= 	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
OBJ_BONUS 		= 	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME_B))


all:		$(NAME)

$(NAME):	$(OBJ)
	@make --no-print-directory full -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(MLX_A) $(OTHER_LIBS)
	@echo "$(GREEN)libasm successfully compiled! $(BASE_COLOR)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@make --no-print-directory full -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT_A) $(MLX_A) $(OTHER_LIBS)
	@echo "$(GREEN)libasm bonuses successfully compiled! $(BASE_COLOR)"

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)libasm objects files cleanned! $(BASE_COLOR)"

fclean:	clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(CYAN)libasm executable file $(BLUE)" $(NAME) "$(CYAN)&$(BLUE) " $(NAME_BONUS) "cleanned!$(BASE_COLOR)"

re: fclean all 

.PHONY :	all bonus clean fclean re
