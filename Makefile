GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m
SRC = main.c\
	close_win.c\
	move.c\
	init_game_win.c\
	count_lines.c\
	putline.c\
	read_map.c\
	invalid_walls.c\
	invalid_chars.c\
	invalid_args.c\
	invalid_map.c\
	invalid_images.c\
	ft_error.c\
	free_map.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\

MAKEFLAGS += --no-print-directory
OBJS = $(SRC:.c=.o)
LIB = libft/libft.a
HEADERS = so_long.h 
NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLXFLAFS = -Lminilibx-linux -lmlx -lXext -lX11

all: $(NAME)
	@echo "$(GREEN)so_long compiled!$(NC)"

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME):
	@echo "$(YELLOW)"
	@make -C ./libft
	@pid=$$! ; \
	total=50 ; \
	i=0 ; \
	while [ $$i -le $$total ]; do \
		sleep 0.05 ; \
		i=$$(($$i + 1)) ; \
		percent=$$(($$i * 100 / ($$total + 1))) ; \
		printf "\rCompiling so_long ... %3d%%" "$$percent" ; \
	done ; \
	wait $$pid ; \

	@echo "$(NC)"
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MLXFLAFS)
clean:
	
	@echo "$(RED)"
	rm -f $(OBJS)
	@make clean -C libft
	@echo "$(GREEN)so_long cleaned!$(NC)"

fclean: clean
	@echo "$(RED)"
	rm -f $(NAME)
	@make fclean -C libft
	@echo "$(GREEN)fclean done!$(NC)"
	
re: fclean all