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

ASMFLAGS 		= 	-f elf64

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
SRC_NAMES 		=	ft_strlen.s \
						ft_strcpy.s \
						ft_strcmp.s \
						ft_write.s \
						ft_read.s \
						ft_strdup.s

SRC_NAMES_B		=	ft_strlen.s \
						ft_strcpy.s \
						ft_strcmp.s \
						ft_write.s \
						ft_read.s \
						ft_strdup.s

SRC 				=	$(addprefix $(SRC_DIR), $(SRC_NAMES))
SRC_BONUS		=	$(addprefix $(SRC_DIR), $(SRC_NAMES_B))

OBJ_DIR 			= 	obj/
OBJ_NAME 		= 	$(SRC_NAMES:.s=.o)
OBJ_NAME_B		=	$(SRC_NAMES_B:.s=.o)
OBJ 				= 	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
OBJ_BONUS 		= 	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME_B))


all:		$(NAME)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ) 
	@echo "$(GREEN)libasm successfully compiled! $(BASE_COLOR)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.s
	@mkdir -p $(dir $@)
	@$(CC) $(ASMFLAGS) $< -c -o $@
	@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	ar -rcs $(NAME_BONUS) $(OBJ_BONUS) 
	@echo "$(GREEN)libasm bonuses successfully compiled! $(BASE_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)libasm objects files cleanned! $(BASE_COLOR)"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(CYAN)libasm executable file $(BLUE)" $(NAME) "$(CYAN)&$(BLUE) " $(NAME_BONUS) "cleanned!$(BASE_COLOR)"

re: fclean all 

.PHONY :	all bonus clean fclean re
