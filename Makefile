# Compiler
CC = gcc

# Compiler flags
CFLAGS = -W

# Source files
SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/ope/*.c) $(wildcard $(SRC_DIR)/sort/*.c)

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Output file
OUT_FILE = push_swap

# Libraries (if any)
LIBFT_DIR = ./LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

# Default rule
all: $(LIBFT) $(OUT_FILE)

# Rule to create the output file
$(OUT_FILE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(OUT_FILE)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean rule
clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

# Fclean rule
fclean: clean
	rm -f $(OUT_FILE)
	make -C $(LIBFT_DIR) fclean

# Re rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re
