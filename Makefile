NAME = philosophers.a

CC = gcc

INCLUDES = ./include/philosophers.h

SRC = ./src/philosophers.c \
	./src/philosophers_utils.c \
	./src/ft_allocate.c \
	./src/ft_init.c \
	./src/ft_philo.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft/

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

subsystem : header
	make -C ./libft
	cp ./libft/libft.a libft.a

$(NAME): subsystem
	$(CC) $(CFLAGS) $(SRC) libft.a -o philosophers

clean :
	rm -f $(OBJ)
	rm -f $(LIBFT_PATH)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)libft.a
	rm -f libft.a
	rm -f philosophers

re: fclean all
