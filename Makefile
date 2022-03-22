CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I./inc
main_mandatory = push_swap.o
main_bonus = checker_bonus.o
B_DIR = build
HEADER = inc/list.h inc/push_swap.h inc/utils.h
b_HEADER = inc/bonus.h $(HEADER)
SRC = push_swap utils/used_func /utils/algo_500 utils/sending_chunks utils/last_chunk utils/pushing_chunks_to_b utils/pushing_max_to_a utils/pushing utils/swaping utils/rotation utils/ft_atoi list/ft_lstadd_back list/ft_lstlast list/ft_lstdelone list/ft_lstadd_front list/ft_lstclear list/ft_lstnew list/ft_lstsize
SRC_bonus = bonus/used_fnc bonus/ft_lstsize bonus/ft_lstdelone bonus/ft_lstlast bonus/ft_atoi bonus/ft_lstadd_back bonus/ft_lstclear bonus/ft_lstnew bonus/swaping bonus/rotation bonus/pushing bonus/checker_bonus bonus/get_next_line bonus/get_next_line_utils 
OBJ_bonus = $(addprefix $(B_DIR)/, $(SRC_bonus:=.o))
OBJ = $(addprefix $(B_DIR)/, $(SRC:=.o))

NAME = push_swap
bonus = Checker

all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $@

bonus: $(bonus)


$(bonus): $(OBJ_bonus) $(b_HEADER)
	$(CC) $(OBJ_bonus) -o $@

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(B_DIR) 

fclean: clean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: clean fclean re all