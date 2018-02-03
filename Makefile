# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/02/03 19:33:31 by khrechen         ###   ########.fr        #
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

NAME :=					filler

INC_DIR :=				inc/
HEADER :=				$(INC_DIR)filler.h

FILLER_DIR :=			srcs/
FILLER_SRCS :=			main.c
SRCS :=					$(addprefix $(FILLER_DIR), $(FILLER_SRCS))

OBJS_DIR :=				objs/
OBJS :=					$(addprefix $(OBJS_DIR), $(FILLER_SRCS:.c=.o))

LIBFTPRINTF_DIR :=		./libftprintf/
LIBFTPRINTF :=			libftprintf.a

INC :=					-I$(LIBFTPRINTF_DIR)inc/		\
						-I$(LIBFTPRINTF_DIR)libft/inc	\
						-I$(INC_DIR)

CC :=					clang

#CFLAGS :=				-Wall -Werror -Wextra
LIBFTPRINTF_FLAGS :=	-L$(LIBFTPRINTF_DIR) -lftprintf
FLAGS :=				$(INC) $(CFLAGS) $(LIBFTPRINTF_FLAGS)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(FILLER_DIR)%.c
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

pu: fclean 
	make pu -C $(LIBFTPRINTF_DIR)
	git add $(SRCS) $(HEADER)

.PHONY: all lib libclean libfclean clean fclean re norm pu $(NAME)
.SILENT:
