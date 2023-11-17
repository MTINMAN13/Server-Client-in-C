NAME_C = client
NAME_S = server

DEF_COLOR = \033[0;39m
RED = \033[0;38;5;162m
RED2 = \033[0;31m

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.c
OBJ_C = $(SRC_C:.c=.o)

LIBFT = libft.a

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

all : server client
server: libft $(OBJ_S)
		@ $(CC) $(FLAGS) -o $(NAME_S) $(OBJ_S) $(LIBFT)
		@echo "$(RED)server rdy$(DEF_COLOR)"


client: libft $(OBJ_C)
		@ $(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) $(LIBFT)
		@echo "$(RED2)client rdy$(DEF_COLOR)"


libft:
		@ make -C libft/

clean:
		@ $(RM) $(OBJ_S) $(OBJ_C)
		@ $(RM) $(NAME_S) $(NAME_C)
		@echo "$(RED2)               server wiped! have a nice day ;-)$(DEF_COLOR)"
		@echo "$(RED)               please recompile to proceed.$(DEF_COLOR)"
		@sleep 1

fclean: clean
		@ $(RM) $(NAME_S) $(NAME_C)
		@ $(RM) libft.a
		@ make -C libft/ clean
		@clear
		@echo "$(RED2)               all wiped boss! have a nice day ;-)$(DEF_COLOR)"
		@sleep 1
		@clear

re: fclean all

norm:
		@clear
		@norminette server.c client.c minitalk.h

.PHONY: all libft clean fclean re norm
