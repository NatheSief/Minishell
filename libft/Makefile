# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 20:58:55 by nsiefert          #+#    #+#              #
#    Updated: 2024/11/25 12:38:48 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror -g3

# Folders
INCLUDE		=	includes/
LIBFT 		=	libft/

OBJ_DIR		=	obj/

RM			=	@rm -f

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

LIBFTSRC = 	ft_atoi.c	 			\
			ft_bzero.c 				\
			ft_isalnum.c 			\
			ft_isalpha.c 			\
			ft_isascii.c 			\
			ft_isdigit.c 			\
			ft_isprint.c 			\
			ft_memchr.c 			\
			ft_memcmp.c 			\
			ft_memcpy.c 			\
			ft_memmove.c 			\
			ft_memset.c 			\
			ft_strchr.c 			\
			ft_strlcat.c 			\
			ft_strlcpy.c 			\
			ft_strlen.c 			\
			ft_strncmp.c 			\
			ft_strnstr.c 			\
			ft_strrchr.c 			\
			ft_tolower.c 			\
			ft_toupper.c 			\
			ft_calloc.c 			\
			ft_strdup.c 			\
			ft_substr.c 			\
			ft_strjoin.c 			\
			ft_strtrim.c 			\
			ft_split.c 				\
			ft_itoa.c 				\
			ft_strmapi.c 			\
			ft_striteri.c 			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c 			\
			ft_putendl_fd.c 		\
			ft_putnbr_fd.c			\
			ft_lstnew.c 			\
			ft_lstadd_front.c 		\
			ft_lstsize.c 			\
			ft_lstlast.c 			\
			ft_lstadd_back.c 		\
			ft_lstdelone.c 			\
			ft_lstclear.c 			\
			ft_lstiter.c 			\
			ft_lstmap.c				\
			ft_print_hex.c			\
			ft_print_ptr.c			\
			ft_print_hex.c			\
			ft_printf_utils.c		\
			ft_print_unsigned.c		\
			ft_printf.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_countchar.c			\
			ft_realloc.c			\
			rmv_lst.c				\
			ft_get_next_char.c		\
			free_tab.c				\
			ft_is_white_space.c		\

# LIBFT
SRC_LIBFT	= 	$(addprefix $(LIBFT), $(LIBFTSRC))
OBJ_LIBFT	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_LIBFT)
	@ar rc $(NAME) $(OBJ_LIBFT)
	@ranlib $(NAME)
	
# Rule to create object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation rule for .c files to .o files
$(OBJ_DIR)%.o: $(LIBFT)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_LIBFT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
