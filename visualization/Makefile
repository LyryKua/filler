# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/03/07 11:00:31 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=				\033[

NORMAL :=				$(SWITCH)0m
BOLD :=					$(SWITCH)1m
RED :=					$(SWITCH)31m
GREEN :=				$(SWITCH)32m
YELLOW :=				$(SWITCH)33m
CYAN :=					$(SWITCH)36m
LIGHT_RED :=			$(SWITCH)91m
LIGHT_YELLOW :=			$(SWITCH)93m
LIGHT_GREEN :=			$(SWITCH)92m
LIGHT_CYAN :=			$(SWITCH)96m

NAME :=					magic

HEADER :=				visualization.h

SRCS :=					draw.c			\
						draw_o.c		\
						draw_x.c		\
						graphics.c		\
						main.c			\
						plateau_piece.c

OBJS_DIR :=				objs/
OBJS :=					$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFTPRINTF_DIR :=		../libftprintf/
LIBFTPRINTF :=			libftprintf.a

INC :=					-I$(LIBFTPRINTF_DIR)inc/		\
						-I$(LIBFTPRINTF_DIR)libft/inc	\
						-I.

CC :=					clang

#CFLAGS :=				-Wall -Werror -Wextra
MLX_FLGAS :=			-lmlx -framework OpenGL -framework AppKit
LIBFTPRINTF_FLAGS :=	-L$(LIBFTPRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(LIBFTPRINTF_FLAGS) $(MLX_FLGAS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@  

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

lib: $(LIBFTPRINTF)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

libclean:
	make clean -C $(LIBFTPRINTF_DIR)

libfclean:
	make fclean -C $(LIBFTPRINTF_DIR)

clean: libclean
	rm -rf $(OBJS_DIR)

fclean: clean libfclean
	rm -f $(NAME)

re: fclean all

norm:
	make norm -C $(LIBFTPRINTF_DIR)
	norminette $(SRCS) $(HEADER)

pu: 
	make pu -C $(LIBFTPRINTF_DIR)
	git add Makefile .gitignore author $(SRCS) $(HEADER)
	git status

.PHONY: all lib libclean libfclean clean fclean re norm pu $(NAME) $(LIBFTPRINTF)
