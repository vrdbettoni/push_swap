NAME		=	push_swap

CC			=	clang
INCL1		=	srcs/push_swap.h
INCL2		=	checker_srcs/checker.h
CFLAGS		=	-Wall -Wextra -Werror

OBJS_PATH1	=	srcs
OBJS_PATH2	=	checker_srcs

OBJ			=	$(SRCS1:.c=.o)
OBJI		=	$(SRCS2:.c=.o)
OBJ1		=	$(addprefix $(OBJS_PATH1)/, $(SRCS1:.c=.o))
OBJ2		=	$(addprefix $(OBJS_PATH2)/, $(SRCS2:.c=.o))

SRCS1		=	push_swap.c				short_stack.c\
				operations.c			utils.c\
				annex_functions.c

SRCS2		=	checker.c				get_next_line.c\
				operations.c			utils.c



all:		$(NAME)

$(NAME): 	$(OBJ1) $(OBJ2)
			@cd srcs && $(CC) $(CFLAGS) -o push_swap $(OBJ)
			@cd checker_srcs && $(CC) $(CFLAGS) -o checker $(OBJI)
			@mv ./srcs/push_swap ./
			@mv ./checker_srcs/checker ./

			@echo "\033[32m > \033[1m$(NAME)\033[0;32m and \033[1m checker\033[0;32m created !\033[0m"

%/*.o:	%/*.c
					@$(CC) $(CFLAGS) -c $< -o $@


clean:
			@rm srcs/*.o 2>/dev/null || true
			@rm checker_srcs/*.o 2>/dev/null || true
			@echo "\033[31m > \033[1mobjs/*\033[0;31m delete.\033[0m"

fclean:		clean
			@rm -rf push_swap 2>/dev/null || true
			@rm -rf checker 2>/dev/null || true
			@rm -rf problem* 2>/dev/null || true
			@rm -rf limit_arg 2>/dev/null || true
			@echo "\033[31m > \033[1m$(NAME)\033[0;31m and \033[1mchecker\033[0;31m delete.\033[0m"

re:			fclean all

.PHONY:		all clean fclean re