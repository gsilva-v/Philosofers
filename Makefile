NAME = philo
NAME_BONUS = 

CC = gcc

# CFLAGS = -g -Wall -Werror -Wextra

CFLAGS = -g -pthread

RM = rm -rf

INCLUDE = -I ./includes/
INCLUDE_BONUS = -I ./includes/

PATH_SRC = ./srcs/
PATH_MAIN = $(PATH_SRC)main/
PATH_MSG = $(PATH_SRC)message/
PATH_UTILS = $(PATH_SRC)utils/

PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_MSG)error_message.c\
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_atoi.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*/*.o -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)message/
	@mkdir -p $(PATH_OBJS)utils/
	$(CC) $(CFLAGS) $(INCLUDE) -I. -c $< -o $@

clean:
	@echo "\033[1;33mCleaning objects\033[0m"
	@$(RM) $(PATH_OBJS)
	@echo "\033[1;32mDone!\033[0m"

fclean: clean
	@echo  "\033[1;33mCleaning all\033[0m"
	@$(RM) $(NAME)
	@echo  "\033[1;33mCleaning binaries\033[0m"
	@echo "\033[1;32mDone!\033[0m"

re: fclean all

.PHONY: all re clean fclean