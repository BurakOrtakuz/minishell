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
					@$(CC) $(FLAGS) $^ -o ./bin/$@
					@printf "\n\033[92m   Downloading... \033[0m\n  "
					@printf "\033[92m █"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "\033[0m\n\n"
					@echo "   GitHub    ~>  \033[4;1;34mburakortakuz\033[0m"
					@echo "   42 Intra  ~>  \033[4;1;34mbortakuz\033[0m \n"
					@echo "   GitHub    ~>  \033[4;1;34menverbey\033[0m"
					@echo "   42 Intra  ~>  \033[4;1;34menvyilma\033[0m \n"

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
					@make -C $(LIBFT_PATH) all
run:				all
					./bin/$(NAME)
clean:
					@rm -rf $(OBJ_DIR) $(MAIN_EXECUTABLE)
					@make -C $(LIBFT_PATH) clean
					@printf "\n\033[91m   Deleting... \033[0m\n  "
					@printf "\033[91m █"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "█"
					@sleep 0.01
					@printf "\033[0m\n\n"
					@clear

fclean:				clean
					@rm -rf ./bin
					@make -C $(LIBFT_PATH) fclean

cl:
	@clear

re:					fclean all
rre: 				re cl
c:					all cl

.PHONY:				all clean fclean re