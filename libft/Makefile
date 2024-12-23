# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 20:58:55 by nsiefert          #+#    #+#              #
#    Updated: 2024/12/19 09:55:52 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror -g3

#Folders
INCLUDE		=	include/
LIBFT 		=	libft/
PRINTF 		=	printf/
GNL 		=	gnl/
PERSO		=	perso/

OBJ_DIR		=	obj/

RM			=	@rm -f

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

LIBFTSRC = 	ft_atoi.c	 				\
			ft_bzero.c 					\
			ft_isalnum.c 				\
			ft_isalpha.c 				\
			ft_isascii.c 				\
			ft_isdigit.c 				\
			ft_isprint.c 				\
			ft_memchr.c 				\
			ft_memcmp.c 				\
			ft_memcpy.c 				\
			ft_memmove.c 				\
			ft_memset.c 				\
			ft_strchr.c 				\
			ft_strlcat.c 				\
			ft_strlcpy.c 				\
			ft_strlen.c 				\
			ft_strncmp.c 				\
			ft_strnstr.c 				\
			ft_strrchr.c 				\
			ft_tolower.c 				\
			ft_toupper.c 				\
			ft_calloc.c 				\
			ft_strdup.c 				\
			ft_substr.c 				\
			ft_strjoin.c 				\
			ft_strtrim.c 				\
			ft_split.c 					\
			ft_itoa.c 					\
			ft_strmapi.c 				\
			ft_striteri.c 				\
			ft_putchar_fd.c				\
			ft_putstr_fd.c 				\
			ft_putendl_fd.c 			\
			ft_putnbr_fd.c				\

LIBFTSRCB =	ft_lstnew.c 				\
			ft_lstadd_front.c 			\
			ft_lstsize.c 				\
			ft_lstlast.c 				\
			ft_lstadd_back.c 			\
			ft_lstdelone.c 				\
			ft_lstclear.c 				\
			ft_lstiter.c 				\
			ft_lstmap.c

PRINTFSRC = ft_fd_print_hex.c			\
			ft_fd_print_ptr.c			\
			ft_fd_print_hex.c			\
			ft_fd_printf_utils.c		\
			ft_fd_print_unsigned.c		\
			ft_fd_printf.c				\
			ft_printf.c					\

GNLSRC	  = get_next_line.c				\
			get_next_line_utils.c		\

PERSOSRC  =	ft_countchar.c				\
			ft_tabsize.c				\
			ft_free_tab.c				\
			ft_iswhitespace.c			\
			print_tab.c					\

# LIBFT
SRC_LIBFT	= 	$(addprefix $(LIBFT), $(LIBFTSRC))
OBJ_LIBFT	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRC:.c=.o))
# LIBFT-BONUS
SRC_LIBFTB	= 	$(addprefix $(LIBFT), $(LIBFTSRCB))
OBJ_LIBFTB	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRCB:.c=.o))
# PRINTF
SRC_PRINTF	=	$(addprefix $(PRINTF), $(PRINTFSRC))
OBJ_PRINTF	= 	$(addprefix $(OBJ_DIR), $(PRINTFSRC:.c=.o))
# GET_NEXT_LINE
SRC_GNL		=	$(addprefix $(GNL), $(GNLSRC))
OBJ_GNL		= 	$(addprefix $(OBJ_DIR), $(GNLSRC:.c=.o))
# PERSONNAL FUNCTIONS
SRC_PERSO	=	$(addprefix $(PERSO), $(PERSOSRC))
OBJ_PERSO	= 	$(addprefix $(OBJ_DIR), $(PERSOSRC:.c=.o))

OBJF		=	.cache_exists

all: print_lib $(NAME)

print_lib :
	@echo "$(MAGENTA)     /\__\      ___        /\  \         /\  \         /\  \     	$(RED)A	$(DEF_COLOR)"
	@echo "$(MAGENTA)    /:/  /     /\  \      /::\  \       /::\  \        \:\  \    	$(RED)M	$(DEF_COLOR)"
	@echo "$(MAGENTA)   /:/  /      \:\  \    /:/\:\  \     /:/\:\  \        \:\  \   	$(RED)E	$(DEF_COLOR)"
	@echo "$(MAGENTA)  /:/  /       /::\__\  /::\_\:\__\   /::\_\:\  \       /::\  \  	$(RED)L	$(DEF_COLOR)"
	@echo "$(MAGENTA) /:/__/     __/:/\/__/ /:/\:\ \:|__| /:/\:\ \:\__\     /:/\:\__\ 	$(RED)I	$(DEF_COLOR)"
	@echo "$(MAGENTA) \:\  \    /\/:/  /    \:\_\:\/:/  / \/__\:\ \/__/    /:/  \/__/ 	$(RED)O	$(DEF_COLOR)"
	@echo "$(MAGENTA)  \:\  \   \::/__/      \:\ \::/  /       \:\__\     /:/  /      	$(RED)R	$(DEF_COLOR)"
	@echo "$(MAGENTA)   \:\  \   \:\__\       \:\/:/  /         \/__/     \/__/       	$(RED)E	$(DEF_COLOR)"
	@echo "$(MAGENTA)    \:\__\   \/__/        \::/__/                                	$(RED)E	$(DEF_COLOR)"
	@echo "$(MAGENTA)     \/__/                 _                            		  		$(DEF_COLOR)"
	
$(NAME): $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_PERSO) $(OBJ_PRINTF_FD)
	@ar rc $(NAME) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_PERSO) $(OBJ_PRINTF_FD)
	@ranlib $(NAME)
	
$(OBJ_DIR)%.o: $(LIBFT)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_FD)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PERSO)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_PERSO) $(OBJ_PRINTF_FD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re print_lib