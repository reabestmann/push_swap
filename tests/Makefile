# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:59:26 by rbestman          #+#    #+#              #
#    Updated: 2025/04/13 23:33:05 by rbestman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MAIN_DIR = main

# Source files (excluding main.c)
SRC_FILES = $(SRC_DIR)/create_stack.c \
	$(SRC_DIR)/error_utils.c \
	$(SRC_DIR)/swap.c \
	$(SRC_DIR)/push.c \
	$(SRC_DIR)/rotate.c \
	$(SRC_DIR)/reverse_rotate.c \
	$(SRC_DIR)/sort_stack.c \
	$(SRC_DIR)/find_nodes.c \
	$(SRC_DIR)/node_utils.c

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

# main files
MAIN_FILES = $(MAIN_DIR)/main.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(MAIN_FILES:.c=.o)

# Output executable for tests
NAME = push_swap

# Compile test program
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

