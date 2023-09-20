NAME    	=	minishell
CC      	=	gcc
FLAGS   	=	-Wall -Wextra -Werror
SRC_DIR 	=	./src
OBJ_DIR 	=	./obj
SRC     	=   $(SRC_DIR)/default_command.c

LIBFT_PATH	=	$(SRC_DIR)/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

OBJS		=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
MAIN		=	$(SRC_DIR)/main.c

all:    			$(NAME)

$(NAME):			$(LIBFT) $(MAIN) $(OBJS)
					@mkdir -p ./bin
					$(CC) $(FLAGS) $^ -o ./bin/$@

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
					make -C $(LIBFT_PATH) all
run:				all
					./bin/$(NAME)
clean:
					rm -rf $(OBJ_DIR) $(MAIN_EXECUTABLE)
					make -C $(LIBFT_PATH) clean

fclean:				clean
					rm -rf ./bin
					make -C $(LIBFT_PATH) fclean

re:					fclean all
.PHONY:				all clean fclean re