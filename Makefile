NAME = philosophers

SRCS = $(wildcard srcs/*.c) 
OBJS_DIR = obj/
OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(notdir $(SRCS)))

HEADER = -Iincludes
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -pthread -g
# Wall -Wextra -Werror

vpath %.c srcs

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
AQUA = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)\nCompiling philosophers executable...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(AQUA)philosophers compiled$(RESET)"

$(LIBFT): FORCE
	@echo ""
	@echo "$(YELLOW)compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

clean:
	@make clean -C $(LIBFT_DIR) -s
	@rm -rf $(OBJS_DIR)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@clear
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"
	
clear:
	@clear

re: clear fclean all

test:
	./philosophers 5 800 200 200 7

val:
	valgind --leak-check=yes ./philosophers 5 800 200 200 7

FORCE:

.PHONY: all bonus clean fclean re test val