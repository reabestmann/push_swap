# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:59:26 by rbestman          #+#    #+#              #
#    Updated: 2025/04/02 18:07:55 by rbestman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
TEST_DIR = tests

# Source files (excluding main.c)
SRC_FILES = $(SRC_DIR)/stack_utils.c \
	$(SRC_DIR)/input_handling.c \
	$(SRC_DIR)/swap.c \
	$(SRC_DIR)/push.c \
	$(SRC_DIR)/rotate.c \
	$(SRC_DIR)/reverse_rotate.c \
	$(SRC_DIR)/sort_stack.c \
	$(SRC_DIR)/sort_stack_helpers.c

LIBFT_FILES = $(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_isdigit.c \
 	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_substr.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_itoa.c

PRINTF_FILES = $(PRINTF_DIR)/ft_print_char.c \
	$(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/ft_print_hex.c \
	$(PRINTF_DIR)/ft_print_ptr.c \
	$(PRINTF_DIR)/ft_print_signed_int.c \
	$(PRINTF_DIR)/ft_print_str.c \
	$(PRINTF_DIR)/ft_print_unsigned_int.c \
	$(PRINTF_DIR)/ft_utoa.c

# Test files
TEST_FILES = $(TEST_DIR)/test.c $(TEST_DIR)/test_main.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(TEST_FILES:.c=.o)

# Output executable for tests
TEST_NAME = test_program

# Compile test program
all: $(TEST_NAME)

$(TEST_NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TEST_NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re

