# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/02/04 15:36:49 by khrechen         ###   ########.fr        #
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

NAME :=					khrechen.filler

INC_DIR :=				inc/
HEADER :=				$(INC_DIR)filler.h

FILLER_DIR :=			srcs/
FILLER_SRCS :=			insert_piece.c		\
						lists.c				\
						main.c				\
						plateau_piece.c		\
						putsqr.c			\
						get_evaluation.c	\
						wave.c
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
	echo "$(YELLOW)Linking binary...$(NORMAL)"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	echo "$(LIGHT_GREEN)$(NAME)$(GREEN) is your binary! Enjoy!$(NORMAL)"

$(OBJS_DIR)%.o: $(FILLER_DIR)%.c
	echo "$(CYAN)Compiling $@$(NORMAL)"
	$(CC) $(CFLAGS) $(INC) -c $< -o $@  

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
	echo "$(GREEN)$(OBJS_DIR) created...$(NORMAL)"

lib: $(LIBFTPRINTF)

$(LIBFTPRINTF):
	echo "$(YELLOW)Making $(LIBFTPRINTF)$(NORMAL)"
	make -C $(LIBFTPRINTF_DIR)

libclean:
	echo "$(RED)Cleaning $(LIBFTPRINTF)$(NORMAL)"
	make clean -C $(LIBFTPRINTF_DIR)

libfclean:
	echo "$(RED)Fcleaning $(LIBFTPRINTF)$(NORMAL)"
	make fclean -C $(LIBFTPRINTF_DIR)

clean: libclean
	rm -rf $(OBJS_DIR)
	echo "$(RED)$(OBJS_DIR) deleted$(NORMAL)"

fclean: clean libfclean
	rm -f $(NAME)
	echo "$(RED)$(NAME) deleted$(NORMAL)"

re: fclean all

norm:
	make norm -C $(LIBFTPRINTF_DIR)
	norminette $(SRCS) $(HEADER)

pu: 
	make pu -C $(LIBFTPRINTF_DIR)
	git add Makefile .gitignore author $(SRCS) $(HEADER)
	git status
	echo "$(CYAN)You can commit your files$(NORMAL)"

.PHONY: all lib libclean libfclean clean fclean re norm pu $(NAME) $(LIBFTPRINTF)
.SILENT:
