NAME = minishell

SCRS = src/main.c src/errors.c src/token.c src/utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIBFT = lib/libft/libft.a

RLFLAG = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	@make -C lib/libft
	@$(CC) $(CFLAGS) $(SCRS) $(LIBFT) -o $(NAME) $(RLFLAG)
	@echo "\033[1;92m Minishell is ready! \033[0m"

val: re
	make clean
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supressions.supp -s ./minishell

clean:
	@make clean -C lib/libft
	$(RM) $(OBJS)
	@echo "\033[38;2;255;165;0m Objects are cleaned! \033[0m"

fclean: clean
	@make fclean -C lib/libft
	$(RM) $(NAME)
	@echo "\033[31m Minishell is cleaned! \033[0m"

re: fclean all

.PHONY : all clean fclean re