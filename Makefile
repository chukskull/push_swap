CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./inc

B_DIR = build
SRC = push_swap list/ft_lstnew
OBJ = $(addprefix $(B_DIR)/, $(SRC:=.o))

NAME = push_swap

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all