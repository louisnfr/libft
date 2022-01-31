# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 01:48:13 by lraffin           #+#    #+#              #
#    Updated: 2022/01/31 23:50:53 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =				\
		$(STRING)	\
		$(ISTYPE)	\
		$(MATH)		\
		$(MEMORY)	\
		$(PRINT)	\

STRING =				\
		ft_split_charset.c \
		ft_split_on_first.c \
		ft_split.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strjoin_and_free.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strlen_double_str.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c	\

ISTYPE =			\
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isdigit_comma.c \
		ft_isflag.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_str_is_alnum.c \
		ft_str_is_digit.c \
		ft_str_is_equal.c \
		ft_str_is_only_char.c \

MATH =				\
		ft_abs.c	\
		ft_atoi_base.c \
		ft_atol.c	\
		ft_atoi.c	\
		ft_atoull.c	\
		ft_itoa.c	\
		ft_max.c	\
		ft_min.c	\
		ft_nbrlen_u.c \
		ft_nbrlen_ul.c \
		ft_nbrlen.c \
		ft_rgb_to_color.c \

MEMORY =			\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_clean_free.c \
		ft_free_double_str.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_realloc.c \
		ft_swap.c \

PRINT =						\
		ft_put0xhexa_ret.c	\
		ft_putchar_fd.c		\
		ft_putchar_ret.c	\
		ft_putchar.c		\
		ft_putendl_fd.c		\
		ft_puthexa_ret.c	\
		ft_putnbr_fd.c		\
		ft_putnbr_ret.c		\
		ft_putnbr_u_ret.c	\
		ft_putnbr_u.c		\
		ft_putnbr.c			\
		ft_putstr_fd.c		\
		ft_putstr_n_ret.c	\
		ft_putstr_ret.c		\
		ft_putstr.c			\

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP

vpath %.c $(addprefix $(SRC_DIR)/, . string print memory math string/istype)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(_SUCCESS) $(NAME)"

-include $(DEPS)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "\t$(_YELLOW)compiling$(_RESET) $*.c\r\c"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<
	@echo "$(_CLEAR)"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

norm:
	@echo "[$(_YELLOW)SOURCES$(_RESET)]"
	-@norminette $(SRC_DIR)
	@echo "[$(_YELLOW)INCLUDES$(_RESET)]"
	-@norminette $(INC_DIR)

push:
	git add .
	git status
	git commit -m "libft (make push)"
	git push

.PHONY: all clean fclean re norm push

_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c
