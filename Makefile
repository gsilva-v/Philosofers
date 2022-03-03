NAME = philo
NAME_BONUS = 

CC = gcc

# CFLAGS = -g -Wall -Werror -Wextra

CFLAGS = -g -pthread

RM = rm -rf

INCLUDE = -I ./includes/
INCLUDE_BONUS = -I ./includes/

PATH_SRC = ./srcs/
PATH_FREE = $(PATH_SRC)frees/
PATH_INIT = $(PATH_SRC)init/
PATH_LUNCH = $(PATH_SRC)lunch_control/
PATH_LOG = $(PATH_SRC)log/
PATH_MAIN = $(PATH_SRC)main/
PATH_MSG = $(PATH_SRC)message/
PATH_TIME = $(PATH_SRC)time/
PATH_UTILS = $(PATH_SRC)utils/
PATH_VALID = $(PATH_SRC)validates/


PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_FREE)initial_frees.c \
		$(PATH_INIT)init.c \
		$(PATH_LOG)infos.c \
		$(PATH_LUNCH)lunch.c $(PATH_LUNCH)kitchen.c\
		$(PATH_MSG)error_message.c \
		$(PATH_TIME)time.c\
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_atoi.c $(PATH_UTILS)is_digit.c \
		$(PATH_VALID)validate.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*/*.o -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)frees/
	@mkdir -p $(PATH_OBJS)lunch_control/
	@mkdir -p $(PATH_OBJS)init/
	@mkdir -p $(PATH_OBJS)log/
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)message/
	@mkdir -p $(PATH_OBJS)time/
	@mkdir -p $(PATH_OBJS)utils/
	@mkdir -p $(PATH_OBJS)validates/
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