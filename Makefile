NAME = minishell

SCRS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -lreadline

LIBFT = lib/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C lib/libft
	@$(CC) $(CFLAGS) $(SCRS) $(LIBFT) -o $(NAME)
	@echo "\033[1;92m Minishell is ready! \033[0m"

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