NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

# source files
SRCS = 	src/main.c src/utils_parser.c src/parser.c \
			src/threads.c src/clean.c src/actions \
			src/utils_threads.c \
# object directory
OBJ_DIR = objects

# object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/utils_parser.o \
		$(OBJ_DIR)/clean.o $(OBJ_DIR)/threads.o $(OBJ_DIR)/actions.o  \
		$(OBJ_DIR)/utils_threads.o \


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# compilation
$(OBJ_DIR)/main.o: src/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/parser.o: src/parser.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/parser.c -o $(OBJ_DIR)/parser.o

$(OBJ_DIR)/utils_parser.o: src/utils_parser.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils_parser.c -o $(OBJ_DIR)/utils_parser.o

$(OBJ_DIR)/clean.o: src/clean.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/clean.c -o $(OBJ_DIR)/clean.o

$(OBJ_DIR)/threads.o: src/threads.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/threads.c -o $(OBJ_DIR)/threads.o

$(OBJ_DIR)/utils_threads.o: src/utils_threads.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils_threads.c -o $(OBJ_DIR)/utils_threads.o

$(OBJ_DIR)/actions.o: src/actions.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/actions.c -o $(OBJ_DIR)/actions.o

# object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all