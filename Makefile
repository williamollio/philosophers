NAME = philosophers.a

CC = gcc

INCLUDES = ./include/philosophers.h

SRC = ./src/philosophers.c \
	./src/philosophers_utils.c \
	./src/ft_allocate.c \
	./src/ft_init.c \
	./src/ft_philo.c \
	./src/ft_state.c \
	./src/ft_destroy.c \
	./src/ft_checker.c \
	./src/ft_libft.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -lpthread

all: $(NAME)

info: header

define HEADER


                _ _ _       _             _     _ _                       _
               | | (_)     ( )           | |   (_) |                     | |
 __      _____ | | |_  ___ |/ ___   _ __ | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___
 \\ \\ /\\ / / _ \\| | | |/ _ \\  / __| | '_ \\| '_ \\| | |/ _ \\/ __|/ _ \\| '_ \\| '_ \\ / _ \\ '__/ __|
  \\ V  V / (_) | | | | (_) | \\__ \\ | |_) | | | | | | (_) \\__ \\ (_) | |_) | | | |  __/ |  \\__ \\
   \\_/\\_/ \\___/|_|_|_|\\___/  |___/ | .__/|_| |_|_|_|\\___/|___/\\___/| .__/|_| |_|\\___|_|  |___/
                                   | |                             | |
                                   |_|                             |_|

endef
export HEADER

header:
	@echo "\x1b[35m$$HEADER\x1b[0m"

$(NAME): header
	$(CC) $(CFLAGS) $(SRC) -o philo

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f philo

re: fclean all
